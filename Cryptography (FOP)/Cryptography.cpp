#include <iostream>
using namespace std;

// Function to encrypt message
string encrypt(string key, string msg)
{
    string code = "";
    int i = 0, j = 0;
    
    while (msg[i] != '\0')
    {
        code += char(int(msg[i]) + int(key[j]) - 62);
        // Display operation in iteration for understanding
        // cout << code << " = " << msg[i] << " + " << key[j] << " - 62" << endl;
        i++;
        j++;
        if (key[j] == '\0')
        {
            j = 0;
        }
    }
    return code;
}

// Function to decrypt message
string decrypt(string key, string code)
{
    string msg = "";
    int i = 0, j = 0;
    while (code[i] != '\0')
    {
        msg += char(int(code[i]) - int(key[j]) + 62);
        // Display operation in iteration for understanding
        // cout << msg << " = " << code[i] << " - " << key[j] << " + 62" << endl;
        i++;
        j++;
        if (key[j] == '\0')
        {
            j = 0;
        }
    }
    return msg;
}

// Main function for testing encrypt and decrypt functions
main()
{
    string Emsg, Ekey, code, Dkey, Dmsg;

    cout << "Enter a message to encrypt: ";
    getline(cin, Emsg);
    cout << "Now enter an ecryption key: ";
    getline(cin, Ekey);
    code = encrypt(Ekey, Emsg);
    cout << "Your message is encrypted sucessfully. \nYour encoded message is: " << code << endl;
    cout << "Enter your secret key to decrypt: ";
    getline(cin, Dkey);
    Dmsg = decrypt(Dkey, code);
    cout << "Your message is decrypted sucessfully. \nYour decoded message is: " << Dmsg << endl;
}