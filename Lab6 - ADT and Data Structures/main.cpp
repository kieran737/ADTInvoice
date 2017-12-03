/*-----------------------------------------------------------------------------

Name: Kieran Hodge

Date: 10.03.2015

Lab number: 6

--------------------------------------------------------------------------------
Program Description: This Program will be using a structure to allow the user to 
input data into, then store the data for when the program requests it and then the
output process will be using the structure to post the data up onto the command 
prompt in an invoice format, the program will also add the standard VAT on to the end
price which is currently 20%.
--------------------------------------------------------------------------------*/
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <windows.h>

using namespace std;

//Creating the structure and declaring the variables.
struct invoice
{
	char description[40];
	int productId;
	int quantity;
	float unitPrice;
	float lineTotal;
	float subTotal;
	float salesTax;
	float total;
};
int main ()
{
	//Instructions on how to enter the data into the program so it can be formatted properly on the invoice.
	cout << setw (51) << endl << "INVOICE CALCULATOR" << endl << endl;
	system ("color 04");
	cout << setw (48) << "INSTRUCTIONS" << endl;
	cout << setw (69) << "Please Enter Data into the Program WITHOUT Spaces" << endl << endl;
	cout << setw (71) << "When Entering the item title instead of entering full" << endl;
	cout << setw (66) << "name like this Playstation 3, only enter PS3" << endl << endl;
	cout << setw (69) << "The Product ID can ONLY be represented by Numbers" << endl << endl;
	cout << setw (70) <<"******************************************************" << endl << endl;
	Sleep(3000);
	system ("color 07");
	//Asking the user to input the data into the program, this will be senting the data to the variables inside of the structure.
	invoice inputDescription;
	cout << "Enter Item title: ";
	cin >> inputDescription.description;

	invoice inputProductID;
	cout << "Enter Product ID: ";
	cin >> inputProductID.productId;
	
	invoice inputQuantity;
	cout << "Enter Quantity of Item(s): ";
	cin >> inputQuantity.quantity;

	invoice inputUnitprice;
	cout << "Enter Unit Price: " << (char)156;
	cin >> inputUnitprice.unitPrice;

	//Calculating the Subtotal, Sales Tax, Total and Line Total, this will be pulling the data from the structure that the user has recently entered.
	invoice calSubtotal;
	calSubtotal.subTotal = inputUnitprice.unitPrice * inputQuantity.quantity;

	invoice calSalestax;
	calSalestax.salesTax = calSubtotal.subTotal * 0.2; 

	invoice calTotal;
	calTotal.total = calSalestax.salesTax + calSubtotal.subTotal;

	invoice calLinetotal;
	calLinetotal.lineTotal = inputQuantity.quantity * inputUnitprice.unitPrice;

	//Clearing the Console window for next process
	system("cls");

	//Outputting the Data that has been entered / calculated and formating the console into an invoice layout.
	cout << setw (19)  << "  Product ID  " << "  Description  " << "  Quantity  " << "  Unit Price  " << "  Line Total  " << endl;
	cout << '\t' << inputProductID.productId;
	cout << "\t\t" << inputDescription.description;
	cout << "\t\t" << inputQuantity.quantity; 
	cout << "\t" << (char)156 << inputUnitprice.unitPrice;
	cout << "\t\t" << (char)156 << calLinetotal.lineTotal << endl << endl;
	cout << setw (69)<< "Subtotal: " << (char)156 << calSubtotal.subTotal << endl;
	cout << setw (70)<< "Sales Tax: " << (char)156 << calSalestax.salesTax << endl;
	cout << setw (70)<< "Total Due: " << (char)156 << calTotal.total << endl;

	//End if Program.
	system("pause");
}
