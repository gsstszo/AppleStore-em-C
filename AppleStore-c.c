#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PRODUCTS 30

struct Produto {
  char name[50];
  char code[10];
  char color[30];
  char category[30];
  char storage[10];
  int year;
  int stock;
  int id;
  float price;
};

const char* categories[] = {
    "",           "iPhone",      "MacBook",          "iPad",
    "AirPods",    "Apple Watch", "Mac mini",         "iMac",
    "Mac Studio", "Mac Pro",     "Apple Vision Pro", "HomePod",
    "Apple TV",   "AirTag"};

struct Produto products[MAX_PRODUCTS];
int amount = 0;
int next_id = 1;

bool is_valid_text(char text[]) {
  if (text[0] == '\0') {
    printf("Invalid! Please enter valid text.\n");
    return false;
  } else {
    return true;
  }
}
bool is_valid_position(int id) { return id == 1; }
bool is_valid_amount(int amount) { return amount > 0; }

void clearInputBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
  // essa funcao aq e para nao ficar usando o getchar() toda hora
  // principalmente quando for em um
}

void pause_screen() {
  clearInputBuffer();
  printf("\nPress Enter to continue...");
  getchar();
}

void CreateProduct() {
  bool verification_while;
  int option;
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
    printf("Enter the storage: ");
    fgets(products[amount].storage, sizeof(products[amount].storage), stdin);
    products[amount].storage[strcspn(products[amount].storage, "\n")] = '\0';
  } while (!is_valid_text(products[amount].storage));

  do {
    printf("Enter the category:\n");
    printf("1. iPhone\n2. MacBook\n3. iPad\n4. AirPods\n5. Apple Watch\n");
    printf(
        "6. Mac mini\n7. iMac\n8. Mac Studio\n9. Mac Pro\n10. Apple Vision "
        "Pro\n");
    printf("11. HomePod\n12. Apple TV\n13. AirTag\n");

    scanf(" %d", &option);
    if (option >= 1 && option <= 13) {
      strcpy(products[amount].category, categories[option]);
      verification_while = true;
    } else {
      printf("Invalid option!\n");
      verification_while = false;
    }
  } while (!verification_while);

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
  printf("Name: %s \n",  products[position].name);
  printf("Code: %s \n", products[position].code);
  printf("Id: %d\n", products[position].id);
  printf("Color: %s\n", products[position].color);
  printf("Storage: %s\n", products[position].storage);
  printf("Category: %s\n", products[position].category);
  printf("Year: %d\n", products[position].year);
  printf("Price: %.2f\n", products[position].price);
  printf("Quantity in stock: %d\n", products[position].stock);
  printf("----------------------------\n");
}
void SortByPrice(struct Produto products[], int amount) {
  struct Produto temp;
  if (amount < 2) {
    printf("Not enough products to sort!\n");
  } else {
    for (int i = 0; i < amount - 1; i++) {
      int swapped = 0;
      for (int j = 0; j < amount - 1 - i; j++) {
        if (products[j].price > products[j + 1].price) {
          temp = products[j];
          products[j] = products[j + 1];
          products[j + 1] = temp;
          swapped = 1;
        }
      }
      if (swapped == 0) {
        break;
      }
    }
    printf("Products successfully sorted by price!\n");
  }
}
void LoadData() {
  FILE* arquivo;
  int i = 0;

  arquivo = fopen("products.txt", "r");
  if (arquivo == NULL) {
    printf("Unable to open the file\n");
    return;
  }

  while (fscanf(arquivo, " %49[^|]|%9[^|]|%d|%29[^|]|%29[^|]|%29[^|]|%d|%f|%d",
                products[i].name, products[i].code, &products[i].id,
                products[i].color, products[i].storage, products[i].category,
                &products[i].year, &products[i].price,
                &products[i].stock) == 9) {
    if (products[i].id >= next_id) {
      next_id = products[i].id + 1;
    }
    i++;
    if (i >= MAX_PRODUCTS) break;
  }

  amount = i;
  printf("Data loaded successfully\n");
  fclose(arquivo);
}
void Sortbyid(int amount) {
  if (!is_valid_amount) {
    printf("No products listed\n");
  } else {
    LoadData();
  }
}
void SortByYear(struct Produto products[], int amount) {
  struct Produto temp;
  if (amount < 2) {
    printf("Not enough products to sort!\n");
  } else {
    for (int i = 0; i < amount - 1; i++) {
      int swapped = 0;
      for (int j = 0; j < amount - 1 - i; j++) {
        if (products[j].year > products[j + 1].year) {
          temp = products[j];
          products[j] = products[j + 1];
          products[j + 1] = temp;
          swapped = 1;
        }
      }
      if (swapped == 0) {
        break;
      }
    }
    printf("Products successfully sorted by year!\n");
  }
}
void CountByCategory(struct Produto products[], int amount) {
  if (!is_valid_amount(amount)) {
    printf("No products listed!\n");
  } else {
    for (int i = 1; i <= 13; i++) {
      int counter = 0;
      for (int j = 0; j < amount; j++) {
        if (strcmp(categories[i], products[j].category) == 0) {
          counter++;
        }
      }
      if (counter > 0) {
        printf("%s: %d\n", categories[i], counter);
      }
    }
  }
}
void AveragePrice(struct Produto products[], int amount) {
  float sum_of_products = 0;
  if (!is_valid_amount(amount)) {
    printf("No products listed\n");
  } else {
    for (int i = 0; i < amount; i++) {
      sum_of_products = sum_of_products + products[i].price;
    }
    float average = ((sum_of_products) / amount);
    printf("The average value of the products is R$%.2f\n", average);
  }
}
void HighestPrice(struct Produto products[], int amount) {
  int position = 0;
  if (!is_valid_amount) {
    printf("No products listed\n");
  } else {
    for (int i = 0; i < amount; i++) {
      if (products[i].price > products[position].price) {
        position = i;
      }
    }
    ShowProduct(position);
  }
}
void OldestProduct(struct Produto products[], int amount) {
  int position = 0;
  if (!is_valid_amount) {
    printf("No products listed\n");
  } else {
    for (int i = 0; i < amount; i++) {
      if (products[i].id < products[position].id) {
        position = i;
      }
    }
    ShowProduct(position);
  }
}
void NewestProduct(struct Produto products[], int amount) {
  int position = 0;
  if (!is_valid_amount) {
    printf("No products listed\n");
  } else {
    for (int i = 0; i < amount; i++) {
      if (products[i].id > products[position].id) {
        position = i;
      }
    }
    ShowProduct(position);
  }
}

void ListProduct() {
  if (!is_valid_position) {
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
  printf("Enter the product id: ");
  scanf("%d", &search_id);
  for (int i = 0; i < amount; i++) {
    if (search_id == products[i].id) {
      position = i;
      break;
    }
  }
  if (is_valid_position) {
    ShowProduct(position);
  } else {
    printf("Product not found!\n");
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
          "4 - Storage\n"
          "5 - Category \n"
          "6 - Year \n"
          "7 - Price \n"
          "8 - Stock \n"
          "0 - Cancel \n"
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
            printf("Current Storage: %s\n", products[position].storage);
            printf("Enter the new storage: ");
            fgets(products[position].storage,
                  sizeof(products[position].storage), stdin);
            products[position]
                .storage[strcspn(products[position].storage, "\n")] = '\0';
          } while (!is_valid_text(products[position].storage));
          printf("Storage successfully changed!\n");
          break;
        case 4:
          clearInputBuffer();
          do {
            getchar();
            printf("Current color: %s\n", products[position].color);
            printf("Enter the new color: ");
            fgets(products[position].color, sizeof(products[position].color),
                  stdin);
            products[position].color[strcspn(products[position].color, "\n")] =
                '\0';
          } while (!is_valid_text(products[position].color));
          printf("Color successfully changed! \n");
          break;
        case 5:
          clearInputBuffer();
          do {
            printf("Current category: %s\n", products[position].category);
            printf("Enter the new category: ");
            fgets(products[position].category,
                  sizeof(products[position].category), stdin);
            products[position]
                .category[strcspn(products[position].category, "\n")] = '\0';
          } while (!is_valid_text(products[position].category));
          printf("Category successfully changed!\n");
          break;
        case 6:
          clearInputBuffer();
          do {
            printf("Current year: %d ", products[position].year);
            scanf("%d", &products[position].year);
            if (products[position].year < 1976 ||
                products[position].year > 2027) {
              printf("Invalid year! Enter a year between 1976 and 2027.\n");
            }
          } while (products[position].year < 1976 ||
                   products[position].year > 2027);
          printf("Year successfully changed!\n");
          break;
        case 7:
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
        case 8:
          clearInputBuffer();
          do {
            printf("Enter the quantity in stock: ");
            scanf("%d", &products[position].stock);
            if (products[position].stock < 0) {
              printf("Invalid stock! Enter a positive value.\n");
            }
          } while (products[position].stock < 0);
          printf("Quantity in stock successfully changed!\n");
          break;
        case 9:
          break;
        default:
          break;
      }
    } while (option != 0);

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
  if (!is_valid_position(position)) {
  } else {
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
          printf("\nStock unit successfully added.\n");
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
}
void SaveData() {
  FILE* arquivo;
  arquivo = fopen("products.txt", "w");
  if (arquivo == NULL) {
    printf("Unable to open the file\n");
    return;
  }
  if (amount < 1) {
    printf("No data to save.\n");
  } else {
    for (int i = 0; i < amount; i++) {
      fprintf(arquivo, "%s|%s|%d|%s|%s|%s|%d|%.2f|%d\n", products[i].name,
              products[i].code, products[i].id, products[i].color,
              products[i].storage, products[i].category, products[i].year,
              products[i].price, products[i].stock);
    }
    printf("Data saved successfully\n");
    fclose(arquivo);
  }
}
void MenuPrincipal() {
  int option;

  do {
    system("cls");
    printf("========================================\n");
    printf("              APPLE STORE               \n");
    printf("========================================\n\n");

    printf("1. Register product\n");
    printf("2. List products\n");
    printf("3. Search product\n");
    printf("4. Edit product\n");
    printf("5. Delete product\n");
    printf("6. Manage stock\n");
    printf("7. Save data\n");
    printf("8. Load data\n");
    printf("9. Oldest product\n");
    printf("10. Newest product\n");
    printf("11. Highest price\n");
    printf("12. Average price\n");
    printf("13. Count by category\n");
    printf("14. Sort by year\n");
    printf("15. Sort by price\n");
    printf("16. Sort by id\n");
    printf("0. Exit\n\n");

    printf("Select an option: ");

    scanf("%d", &option);

    switch (option) {
      case 1:
        if (amount >= MAX_PRODUCTS) {
          printf("Registration capacity full\n");
        } else {
          CreateProduct();
        }
        pause_screen();
        break;

      case 2:
        ListProduct();
        pause_screen();
        break;

      case 3:
        SearchProduct();
        pause_screen();
        break;

      case 4:
        UpdateProduct();
        pause_screen();
        break;

      case 5:
        DeleteProduct();
        pause_screen();
        break;

      case 6:
        ManageInventory();
        pause_screen();
        break;

      case 7:
        SaveData();
        pause_screen();
        break;

      case 8:
        LoadData();
        pause_screen();
        break;

      case 9:
        OldestProduct(products, amount);
        pause_screen();
        break;

      case 10:
        NewestProduct(products, amount);
        pause_screen();
        break;

      case 11:
        HighestPrice(products, amount);
        pause_screen();
        break;

      case 12:
        AveragePrice(products, amount);
        pause_screen();
        break;

      case 13:
        CountByCategory(products, amount);
        pause_screen();
        break;

      case 14:
        SortByYear(products, amount);
        pause_screen();
        break;

      case 15:
        SortByPrice(products, amount);
        pause_screen();
        break;

      case 16:
        Sortbyid(amount);
        pause_screen();
        break;

      case 0:
        printf("Goodbye!\n");
        break;

      default:
        printf("Invalid option!\n");
        pause_screen();
        break;
    }

  } while (option != 0);
}

int main() {
  setlocale(LC_NUMERIC, "pt_BR.UTF-8");
  MenuPrincipal();
  return 0;
}
