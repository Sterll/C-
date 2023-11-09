#include <iostream>
#include <vector>

int main() {
    std::vector<int> myVector = {1, 2, 3, 4, 5};

    if (myVector.size() >= 2) {
        // Créez un itérateur pointant vers le deuxième élément (index 1).
        std::vector<int>::iterator it = myVector.begin() + 1;

        // Utilisez la méthode erase() pour supprimer le deuxième élément.
        myVector.erase(it);

        // Affichez le vecteur mis à jour.
        for (int num : myVector) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Le vecteur n'a pas assez d'éléments pour supprimer le deuxième." << std::endl;
    }

    return 0;
}
