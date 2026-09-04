#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produto {
  char name[50];
  char code[10];
  char color[30];
  char category[30];
  int year;
  int stock;
  int id;
  float price;
};

struct Produto products[10];
int amount = 0;
int next_id = 1;

bool is_valid_text(char text[]) {
  if (text[0] == '\0') {
    printf("Invalid! Enter valid text.\n");
    return false;
  } else {
    return true;
  }
}
bool is_valid_position(int id) {
  if (id != -1) {
    return true;
  } else {
    return false;
  }
}
void clearInputBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
  // essa funcao aq e para nao ficar usando o getchar() toda hora
  // principalmente quando for em um
}

void CreateProduct() {
  products[amount].id = next_id;
  printf("Apple Product Registration!\n");
  do {
    printf("Enter the name: ");
    getchar();
    fgets(products[amount].name, sizeof(products[amount].name), stdin);
    products[amount].name[strcspn(products[amount].name, "\n")] =
        '\0';  // isso aq serve para tirar o enter no final do teclado
  } while (!is_valid_text(products[amount].name));

  do {
    printf("Enter the code: ");
    fgets(products[amount].code, sizeof(products[amount].code), stdin);
    products[amount].code[strcspn(products[amount].code, "\n")] = '\0';
  } while (!is_valid_text(products[amount].code));

  do {
    printf("Enter the color: ");
    fgets(products[amount].color, sizeof(products[amount].color), stdin);
    products[amount].color[strcspn(products[amount].color, "\n")] = '\0';
  } while (!is_valid_text(products[amount].color));

  do {
    printf("Enter the category: ");
    fgets(products[amount].category, sizeof(products[amount].category), stdin);
    products[amount].category[strcspn(products[amount].category, "\n")] = '\0';
  } while (!is_valid_text(products[amount].category));

  do {
    printf("Enter the year: ");
    scanf("%d", &products[amount].year);
    if (products[amount].year < 1976 || products[amount].year > 2027) {
      printf("Invalid year! Enter a year between 1976 and 2027.\n");
    }
  } while (products[amount].year < 1976 || products[amount].year > 2027);

  do {
    printf("Enter the price: ");
    scanf("%f", &products[amount].price);
    if (products[amount].price <= 0) {
      printf("Invalid price! Enter a value greater than 0.\n");
    }
  } while (products[amount].price <= 0);

  do {
    printf("Enter the quantity in stock: ");
    scanf("%d", &products[amount].stock);
    if (products[amount].stock < 0) {
      printf("Invalid stock! Enter a positive value.\n");
    }
  } while (products[amount].stock < 0);
  printf("Apple product successfully registered!\n");
  next_id++;
  amount++;
}

void ShowProduct(int position) {
  printf("----------------------------\n");
  printf("Name: %s \n", products[position].name);
  printf("Code: %s \n", products[position].code);
  printf("Id: %d\n", products[position].id);
  printf("Color: %s\n", products[position].color);
  printf("Category: %s\n", products[position].category);
  printf("Year: %d\n", products[position].year);
  printf("Price: %.2f\n", products[position].price);
  printf("Quantity in stock: %d\n", products[position].stock);
  printf("----------------------------\n");
}
void ListProduct() {
  if (amount < 1) {
    printf("No products listed.\n");
  } else {
    printf("--List of Registered Products--\n");
    for (int i = 0; i < amount; i++) {
      ShowProduct(i);
    }
  }
}

int SearchProduct() {
  int search_id;
  int position = -1;
  printf("Enter the id of product: ");
  scanf("%d", &search_id);
  for (int i = 0; i < amount; i++) {
    if (search_id == products[i].id) {
      position = i;
      break;
    }
  }
  if (position != -1) {
    ShowProduct(position);
  } else {
    printf("Product not found!.\n");
  }
  return position;
}
void UpdateProduct() {
  int position = SearchProduct();
  int option;
  if (is_valid_position(position)) {
    do {
      printf("What would you like to change? \n");
      printf(
          ""
          "1 - Name \n"
          "2 - Code \n"
          "3 - Color \n"
          "4 - Category \n"
          "5 - Year \n"
          "6 - Price \n"
          "7 - Stock \n"
          "8 - Cancel \n"
          "\n");
      scanf("%d", &option);
      switch (option) {
        case 1:
          clearInputBuffer();
          do {
            printf("Current name: %s \n", products[position].name);
            printf("Enter the new name: ");
            fgets(products[position].name, sizeof(products[position].name),
                  stdin);
            products[position].name[strcspn(products[position].name, "\n")] =
                '\0';
          } while (!is_valid_text(products[position].name));
          printf("Name successfully changed! \n");

          break;
        case 2:
          clearInputBuffer();
          do {
            getchar();
            printf("Current code: %s \n", products[position].code);
            printf("Enter the new code: ");
            fgets(products[position].code, sizeof(products[position].code),
                  stdin);
            products[position].code[strcspn(products[position].code, "\n")] =
                '\0';
          } while (!is_valid_text(products[position].code));
          printf("Code successfully changed! \n");
          break;
        case 3:
          clearInputBuffer();
          do {
            getchar();
            printf("Current color : %s\n", products[position].color);
            printf("Enter the new color: ");
            fgets(products[position].color, sizeof(products[position].color),
                  stdin);
            products[position].color[strcspn(products[position].color, "\n")] =
                '\0';
          } while (!is_valid_text(products[position].color));
          printf("Color successfully changed! \n");
          break;
        case 4:
          clearInputBuffer();
          do {
            printf("Currente category: %s\n", products[position].category);
            printf("Enter the new category:");
            fgets(products[position].category,
                  sizeof(products[position].category), stdin);
            products[position]
                .category[strcspn(products[position].category, "\n")] = '\0';
          } while (!is_valid_text(products[position].category));
          printf("Category successfully changed!\n");
          break;
        case 5:
          clearInputBuffer();
          do {
            printf("Currente year: %d ", products[position].year);
            scanf("%d", &products[position].year);
            if (products[position].year < 1976 ||
                products[position].year > 2027) {
              printf("Invalid year! Enter a year between 1976 and 2027.\n");
            }
          } while (products[position].year < 1976 ||
                   products[position].year > 2027);
          printf("Year successfully changed!\n");
          break;
        case 6:
          clearInputBuffer();
          do {
            printf("Enter the price: ");
            scanf("%f", &products[position].price);
            if (products[position].price <= 0) {
              printf("Invalid price! Enter a value greater than 0.\n");
            }
          } while (products[position].price <= 0);
          printf("Price successfully changed!\n");
          break;
        case 7:
          clearInputBuffer();
          do {
            printf("Enter the quantity in stock: ");
            scanf("%d", &products[position].stock);
            if (products[position].stock < 0) {
              printf("Invalid stock! Enter a positive value.\n");
            }
          } while (products[position].stock < 0);
          printf("Quantity in stock sucessfully changed!\n");
          break;
        case 8:
          break;
        default:
          break;
      }
    } while (option != 8);

  } else {
    printf("Product not found!\n");
  }
}
void DeleteProduct() {
  int position = SearchProduct();
  if (is_valid_position(position)) {
    for (int i = position; i < amount - 1; i++) {
      products[i] = products[i + 1];
    }
    printf("Product successfully deleted\n");
    amount--;
  };
}
void ManageInventory() {
  int option;
  int temporary_quantity_stock;
  int position = SearchProduct();
  bool temporary_verification = false;
  printf(
      ""
      "1 - Add stock \n"
      "2 - Remove stock \n"
      "3 - View stock \n"
      "4 - Back \n"
      "Select an option:  ");
  scanf("%d", &option);
  switch (option) {
    case 1:
      printf("How many units do you want to add? ");
      scanf("%d", &temporary_quantity_stock);
      if (temporary_quantity_stock < 1) {
        printf("Insufficient units!\n");
      } else {
        products[position].stock =
            products[position].stock + temporary_quantity_stock;
        printf("\n Stock unit successfully added.\n");
      }
      break;
    case 2:
      do {
        printf("How many units do you want to remove? ");
        scanf("%d", &temporary_quantity_stock);
        if (temporary_quantity_stock < 1) {
          printf("Insufficient units!\n");
        } else if (temporary_quantity_stock > products[position].stock) {
          printf("You cannot remove more units than you have in stock.\n");
        } else {
          products[position].stock =
              products[position].stock - temporary_quantity_stock;
          temporary_verification = true;
          printf("\nStock unit withdrawal successfully completed.\n");
        }
      } while (!temporary_verification);
      break;
    case 3:
      printf("--------------------------------------------------\n");
      printf("Name: %s \n", products[position].name);
      printf("Quantity in stock: %d\n", products[position].stock);
      printf("--------------------------------------------------\n");
      break;
    case 4:
      break;
    default:
      break;
  }
}
 void SaveData(){
  
 }
void MenuPrincipal() {
  int option;
  do {
    printf(
        "      APPLE STORE      \n"
        "\n"
        "1. Register product\n"
        "2. List products\n"
        "3. Search product\n"
        "4. Edit product\n"
        "5. Delete product\n"
        "6. Manage inventory\n"
        "7. Save data\n"
        "8. Exit\n\n"
        "Select an option: ");

    scanf("%d", &option);

    switch (option) {
      case 1:
        if (amount >= 10) {
          printf("Registration capacity full \n");
        } else {
          CreateProduct();
        }
        break;
      case 2:
        ListProduct();
        break;
      case 3:
        SearchProduct();
        break;
      case 4:
        UpdateProduct();
        break;
      case 5:
        DeleteProduct();
        break;
      case 6:
        ManageInventory();
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