#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_valid_message(const string &text) {
    for (char c : text) {
        if (!isalpha(static_cast<unsigned char>(c)) && c != ' ') {
            return false;
        }
    }
    return true;
}

string rail_fence_encrypt(const string &plaintext, int rails) {
    if (rails <= 1 || plaintext.empty()) return plaintext;

    vector<string> fence(rails, "");
    int rail = 0;
    int direction = 1;

    for (char c : plaintext) {
        // keep spaces as normal characters
        fence[rail] += c;
        rail += direction;
        if (rail == rails - 1 || rail == 0) direction = -direction;
    }

    string ciphertext;
    for (const string &row : fence) ciphertext += row;
    return ciphertext;
}

string rail_fence_decrypt(const string &ciphertext, int rails) {
    if (rails <= 1 || ciphertext.empty()) return ciphertext;

    int n = static_cast<int>(ciphertext.size());
    // build pattern of rail indices for each character
    vector<int> pattern(n);
    int rail = 0;
    int direction = 1;
    for (int i = 0; i < n; ++i) {
        pattern[i] = rail;
        rail += direction;
        if (rail == 0 || rail == rails - 1) direction = -direction;
    }

    // count how many characters belong to each rail
    vector<int> counts(rails, 0);
    for (int idx : pattern) counts[idx]++;

    // slice the ciphertext into rows according to counts
    vector<string> rows(rails);
    int pos = 0;
    for (int r = 0; r < rails; ++r) {
        if (counts[r] > 0) {
            rows[r] = ciphertext.substr(pos, counts[r]);
            pos += counts[r];
        }
    }

    // rebuild plaintext by walking the pattern and consuming from each row
    vector<int> cur(rails, 0);
    string plaintext;
    plaintext.reserve(n);
    for (int i = 0; i < n; ++i) {
        int r = pattern[i];
        plaintext += rows[r][cur[r]++];
    }

    return plaintext;
}

string read_message_from_file(const string &path) {
    ifstream fin(path);
    string line;
    getline(fin, line);
    return line;
}

int main() {
    cout << "=== Rail Fence Cipher Demo ===\n";
    cout << "1. Encrypt\n2. Decrypt\n3. Read from file and encrypt\nChoose: ";

    int choice;
    cin >> choice;
    cin.ignore();

    string message;
    int rails;

    if (choice == 3) {
        message = read_message_from_file("data/input.txt");
        cout << "Message from file: " << message << "\n";
    } else {
        cout << "Enter message: ";
        getline(cin, message);
    }

    cout << "Enter rails: ";
    cin >> rails;
    if (!is_valid_message(message)) {
        cout << "Invalid input. Only letters and spaces are allowed.\n";
        return 0;
    }

    if (rails <= 0) {
        cout << "Invalid number of rails. Must be >= 1.\n";
        return 0;
    }

    if (!is_valid_message(message)) {
        cout << "Invalid input. Only letters and spaces are allowed.\n";
        return 0;
    }

    if (choice == 1 || choice == 3) {
        cout << "Ciphertext: " << rail_fence_encrypt(message, rails) << "\n";
    } else if (choice == 2) {
        cout << "Plaintext: " << rail_fence_decrypt(message, rails) << "\n";
    } else {
        cout << "Invalid choice.\n";
    }

    return 0;
}
