#include <locale.h>
#include <stdio.h>
#include <string.h>

struct Produto {
  char name[50];
  char code[10];
  char color[30];
  char category[30];
  int year;
  float price;
  int stock;
};

struct Produto products[10];
int amount = 0;

void CreateProduct() {
  printf("Enter the name: ");
  getchar();
  fgets(products[amount].name, sizeof(products[amount].name), stdin);
  products[amount].name[strcspn(products[amount].name, "\n")] =
      '\0';  // isso aq serve para tirar o enter no final do teclado

  printf("Enter the code: ");
  fgets(products[amount].code, sizeof(products[amount].code), stdin);
  products[amount].code[strcspn(products[amount].code, "\n")] = '\0';

  printf("Enter the color: ");
  fgets(products[amount].color, sizeof(products[amount].color), stdin);
  products[amount].color[strcspn(products[amount].color, "\n")] = '\0';

  printf("Enter the category: ");
  fgets(products[amount].category, sizeof(products[amount].category), stdin);
  products[amount].category[strcspn(products[amount].category, "\n")] = '\0';

  printf("Enter the year: ");
  scanf("%d", &products[amount].year);

  printf("Enter the price: ");
  scanf("%f", &products[amount].price);

  printf("Enter the quantity in stock: ");
  scanf("%d", &products[amount].stock);
  amount++;
}

void ListProduct() {
  for (int i = 0; i < amount; i++) {
    printf("\n");
    printf("--List of Registered Products--\n");
    printf("Name: %s \n", products[i].name);
    printf("Code: %s \n", products[i].code);
    printf("Category: %s\n", products[i].category);
    printf("Year: %d\n", products[i].year);
    printf("Price: %.2f\n", products[i].price);
    printf("Quantity in stock: %d\n", products[i].stock);
  }
}

void MenuPrincipal() {
  int option;
  do {
    printf(
        "      APPLE STORE       \n"
        "1. Register product\n"
        "2. List products\n"
        "3. Search product\n"
        "4. Edit product\n"
        "5. Delete product\n"
        "6. Manage inventory\n"
        "7. Save data\n"
        "8. Exit\n\n"
        "Select an option:  ");
    scanf("%d", &option);

    switch (option) {
      case 1:
        CreateProduct();
        break;
      case 2:
        ListProduct();
        break;
      case 3:
        printf("Funcao de BuscarProduto ainda nao implementada\n");
        break;
      case 4:
        printf("Funcao de AlterarProduto ainda nao implementada\n");
        break;
      case 5:
        printf("Funcao de RemoverProduto ainda nao implementada\n");
        break;
      case 6:
        printf("Funcao de GerenciarProduto ainda nao implementada\n");
        break;
      case 7:
        printf("Funcao de SalvarDados ainda nao implementada\n");
        break;
      case 8:
        break;
      default:
        printf("Opcao Invalida!\n");
        break;
    }

  } while (option != 8);
}

int main() {
  setlocale(LC_NUMERIC, "pt_BR.UTF-8");
  MenuPrincipal();
  return 0;
}