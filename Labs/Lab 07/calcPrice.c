#include <stdio.h>

int main () {
  int itemNumber;
  double unitPrice;
  int quantity;
  char purchaseDate[12];

  printf("Enter Item Number: ");
  scanf("%d", &itemNumber);

  printf("Enter Unit Price: ");
  scanf("%lf", &unitPrice);

  printf("Enter Quantity: ");
  scanf("%d", &quantity);

  printf("Enter Purchase Date (mm/dd/yyyy): ");
  scanf("%s", &purchaseDate);


  printf("Item\tUnit Price\tQTY\tPurchase Date\tTotal Amount\n");
  printf("%d\t$%9.2lf\t%d\t%s\t$%9.2lf\n\n", itemNumber, unitPrice, quantity, purchaseDate, unitPrice * quantity);

  return 0;
}
