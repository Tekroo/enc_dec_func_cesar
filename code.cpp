#include <iostream>
#include <string>
#include <locale>
using namespace std;

string enc_func(
                const string &message,
                int key){
                string enctext;
                for (char lettre:message){
                   if (isalpha(lettre)) {
                        char base = isupper(lettre) ? 'A' : 'a';
                        int index = lettre - base;
                        int new_index = (index + key) % 26;
                        char new_lettre = base + new_index;
                        enctext += new_lettre;
                    } else {
                        // Si le caractère n'est pas alphabétique, le conserve tel quel
                        enctext += lettre;
                    }
                }
                return enctext;
}
string dec_func(
                const string &enctext,
                int key){
                string message;
                for (char lettre:enctext){
                   if (isalpha(lettre)) {
                        char base = isupper(lettre) ? 'A' : 'a';
                        int index = lettre - base;
                        int new_index = (index - key + 26) % 26;
                        char new_lettre = base + new_index;
                        message += new_lettre;
                    } else {
                        // Si le caractère n'est pas alphabétique, le conserve tel quel
                        message += lettre;
                    }
                }
                return message;
}

int main()
{
    setlocale(LC_ALL, ""); // Utilisez l'encodage par défaut du système
    string message;
    string enctext;
    int key,num;

    cout<<"Veuillez selectionner un numero :"<<endl;
    cout<<"Numéro 1 pour le cryptage 2 pour le decryptage "<<endl;
    cin>>num;
    if (num==1){
        cout<<"Entrer le message à crypter: ";
        cin>>message;
        cout<<"Entrer la clé de cryptage: ";
        cin>>key;
        string enctext=enc_func(message,key);
        cout<<"Voici votre message chiffré : "<<enctext<<endl;
    }
        else if(num==2){
            cout<<"Entrer le message à décrypter: ";
            cin>>enctext;
            cout<<"Entrer la clé de décryptage: ";
            cin>>key;
            string dectext=dec_func(enctext,key);
            cout<<"Voici votre message déchiffré : "<<dectext<<endl;
        }
        else{
            cout<<"Numéro incorrect!!!";

        }

    return 0;
}
