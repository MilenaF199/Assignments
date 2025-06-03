#include <iostream>
#include <string>
#include <ctime>

using namespace std;


// Constants for RSA
const long P   = 61;                    // Prime
const long Q   = 53;                    // Prime
const long N   = P * Q;                 // Modulus = P * Q = 3233
const long PHI = (P - 1) * (Q - 1);     // φ(N) = 3120
const long E   = 17;                    // Public exponent
const long D   = 2753;                  // Private exponent (E * D ≡ 1 mod PHI)


// Modular exposure: calculates (base^exp) % mod
long modPow(long base, long exp, long mod) {
    long resultado = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            resultado = (resultado * base) % mod;
        }
        exp = exp / 2;
        base = (base * base) % mod;
    }
    return resultado;
}


// Convert a username to a simple number
long calculateAsciiSum(const string &name) {
    long sum = 0;
    for (char c : name) {
        sum += static_cast<int>(c);
    }
    return sum;
}


// Prints the RSA public key (N, E).
void showPublicKey() {
    cout << "\n--- Public key ---\n";
    cout << "Modulus (n) = " << N << "\n";
    cout << "Public Exponent (e) = " << E << "\n";
    cout << "You can share these values with anyone who needs to verify licenses.\n";
    cout << "\n------------------\n";
}


// Generates a license
void generateLicense() {
    cout << "\nEnter username (no spaces): ";
    string username;
    cin >> username;

    cout << "Enter expiration year: ";
    int expirationYear;
    cin >> expirationYear;
    
    long asciiSum = calculateAsciiSum(username);
    long payload = asciiSum + expirationYear;
    long licenseCode = modPow(payload, D, N);
 
    cout << "\n--- Generate license ---\n";
    cout << "Username: " << username << "\n";
    cout << "Expiration Year: " << expirationYear << "\n";
    cout << "ASCII Sum: " << asciiSum << "\n";
    cout << "Payload (asciiSum + year) = " << payload << "\n";
    cout << "License Code (signature) = " << licenseCode << "\n\n";
    cout << "Save this license code and provide it to the user.\n";
    cout << "\n------------------------\n";
 }
 

// Verifies a license code by checking signature and expiration
void verifyLicense() {
    cout << "\nEnter username (no spaces): ";
    string username;
    cin >> username;

    cout << "Enter expected expiration year (e.g., 2025): ";
    int expectedYear;
    cin >> expectedYear;

    cout << "Enter license code (integer): ";
    long licenseCode;
    cin >> licenseCode;

    
    long asciiSum = calculateAsciiSum(username);
    long verifiedPayload = modPow(licenseCode, E, N);

    cout << "\n--- Verification result ---\n";
    cout << "Username: " << username << "\n";
    cout << "ASCII Sum: " << asciiSum << "\n";
    cout << "Expected Expiration Year: " << expectedYear << "\n";
    cout << "Verified Payload = " << verifiedPayload << "\n";

    long expectedPayload = asciiSum + expectedYear;
    if (verifiedPayload != expectedPayload) {
        cout << "=> ERROR: Signature does not match the expected payload.\n";
        cout << "   The license is NOT valid.\n";
        return;
    }

    int licensedYear = static_cast<int>(verifiedPayload - asciiSum);

    time_t t = time(nullptr);
    tm *localTime = localtime(&t);
    int currentYear = localTime->tm_year + 1900;

    cout << "=> Signature is valid. Licensed Year = " << licensedYear << "\n";
    cout << "   Current Year = " << currentYear << "\n";

    if (currentYear <= licensedYear) {
        cout << "=> The license is STILL VALID.\n";
    } else {
        cout << "=> The license HAS EXPIRED.\n";
    }
    cout << "---------------------------\n";
}


// Decrypts an encrypted integer
void decryptMessage() {
    cout << "\nEnter the encrypted number: ";
    long ciphertext;
    cin >> ciphertext;

    long decrypted = modPow(ciphertext, D, N);

    cout << "\n--- Decryption result ---\n";
    cout << "Encrypted number: " << ciphertext << "\n";
    cout << "Decrypted number = " << decrypted << "\n\n";
    cout << "---------------------------\n";
}


// Main menu
int main() {
    cout << "===== RSA for software licenses =====\n";
    cout << "Using primes:\n";
    cout << "P = " << P << ", Q = " << Q << ", N = " << N << "\n";
    cout << "Public Exponent e = " << E << "\n";
    cout << "Private Exponent d = " << D << "\n\n";

    cout << "Select an option:\n";
    cout << "  1) Show public key (N, E)\n";
    cout << "  2) Generate a license code\n";
    cout << "  3) Verify a license code\n";
    cout << "  4) Decrypt a message\n";
    cout << "  0) Exit\n";

    int option;
    cin >> option;
    cin.ignore(1000, '\n'); // clear input buffer

    switch (option) {
        case 0:
            cout << "Exiting...\n";
            break;
        case 1:
            showPublicKey();
            break;
        case 2:
            generateLicense();
            break;
        case 3:
            verifyLicense();
            break;
        case 4:
            decryptMessage();
            break;
        default:
            cout << "Invalid option. Program terminated.\n";
            break;
    }

    return 0;
}