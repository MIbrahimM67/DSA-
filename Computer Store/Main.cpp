#include <iostream>
#include <string>
#include <vector>
#include <fstream>


class Employee {
	
	
	public:
		static int TotalEmp;
		char name[50] = { '0' };
		int Age;
		int Salary;
		char Designation[50];
		char EmployeID[50];
		friend std::ostream& operator <<(std::ostream& out, const Employee& Emp);
		Employee()
		{
			TotalEmp++;

		}
		Employee(char Name1[], int age1,int salary1, char desig[], char employee[]) : Age(age1), Salary(salary1)
		{
			strncpy_s(name, Name1, sizeof(name) - 1); 
			name[sizeof(name) - 1] = '\0';
			strncpy_s(Designation, desig, sizeof(Designation) - 1); 
			Designation[sizeof(Designation) - 1] = '\0';
			strncpy_s(EmployeID, employee, sizeof(EmployeID) - 1); 
			EmployeID[sizeof(EmployeID) - 1] = '\0';
			TotalEmp++;
		}
		std::string Getname()const
		{
			return name;
		}
		int GetAge()const
		{
			return Age;
		}
		int GetSalary()const
		{
			return Salary;
		}
		std::string GetDesignation()const
		{
			return Designation;
		}
		std::string GetEmployeeid()const
		{
			return EmployeID;
		}
		void SetAge(int a)
		{
			Age = a;
		}
		void SetSalary(int a)
		{
			Salary = a;
		}
		void setDesignation(char a[])
		{
			strncpy_s(Designation, a, sizeof(Designation) - 1);

		}
		void setEmployeID(char a[])
		{
			strncpy_s(EmployeID, a,sizeof(EmployeID)-1);
		}
		void setEname(char a[])
		{
			strncpy_s(name, a, sizeof(name) - 1);
		}


	                 // this class will hanlde the employee records
 
};
int Employee::TotalEmp = 0;


class Inventory
{
	
public:
	static int TotalInv;
	int Price;
	char Itemname[50];
	int ProductID;
	friend std::ostream& operator <<(std::ostream& out, const Inventory& INV);
	Inventory()
	{
		TotalInv++;
	}

	Inventory( char Name[50], int ID = 0,int price = 0) :Price(price), ProductID(ID)
	{
		strncpy_s(Itemname, Name, sizeof(Itemname) - 1);
	}
	void SetItemName(char name[50])
	{
		strncpy_s(Itemname, name, sizeof(Itemname) - 1);
	}
	void SetItemPrice(int a)
	{
		Price = a;
	}
	void SetItemID(int a)
	{
		ProductID = a;
	}
	std::string GetItemName()const
	{
		return Itemname;
	}
	int GetItemPrice()const
	{
		return Price;
	}
	int GetItemID()const
	{
		return ProductID;
	}
	
	// this class will handle the inventory
};

int Inventory::TotalInv = 0;


std::ostream& operator <<(std::ostream& out,const Inventory& inv)
{
	out << "ItemName = " << inv.GetItemName() << "\t ItemPrice = " << inv.GetItemPrice()<<"\tProductID = "<<inv.GetItemID()<<std::endl;
	return out;

}


void AddEmploye(std::vector<Employee> &Emp)
{
	Employee Temp;
	char tempS[50];
	int TempInt;
	std::cout << "\t \t Welcome On board, you are hired!, please enter your information for record purposes" << std::endl;
	std::cout << "-> Whats The Employee Name" << std::endl;
	std::cin >> tempS;
	Temp.setEname(tempS);
	std::cout << "-> Choose  Unique id (it could be mix of numbers/Alphabets" << std::endl;
	std::cin >> tempS;

	for (auto& i : Emp)
	{
		if (i.GetEmployeeid() == tempS)
		{
			std::cout << "ID is already occupied, please choose something else" << std::endl;
		}
	}
	Temp.setEmployeID(tempS);
	do {
		std::cout << "-> What is Employee Age , please enter valid Age (18-60)" << std::endl;
		std::cin >> TempInt;
	} while (!(TempInt >= 18 && TempInt <= 60));

	Temp.SetAge(TempInt);
	std::cout << "-> What is Employee Designation" << std::endl;
	std::cin >> tempS;
	Temp.setDesignation(tempS);
	std::cout << "-> What is Employee Salary" << std::endl;
	std::cin >> TempInt;
	Temp.SetSalary(TempInt);

	Emp.push_back(Temp);

}
void UpdateEmp(std::vector<Employee>& Emp)
{
	char tempS[50];
	std::string ID;
	int TempInt;
	int Checkmate = 1;
	std::cout << "Enter the Unique ID of the Employee (NO Spaces)" << std::endl;
	std::cin >> ID;
	for (auto &i : Emp)
	{
		if (i.GetEmployeeid() == ID)
		{
			std::cout << " Record Found! Lets Update it" << std::endl;

			std::cout << "-> Whats The Employee Name" << std::endl;
			std::cin >> tempS;
			i.setEname(tempS);
			std::cout << "-> Choose  Unique id (it could be mix of numbers/Alphabets (No spaces)" << std::endl;
			std::cin >> tempS;

			for (auto& i : Emp)
			{
				if (i.GetEmployeeid() == tempS)
				{
					std::cout << "ID is already occupied, please choose something else" << std::endl;
				}
			}
			i.setEmployeID(tempS);
			do {
				std::cout << "-> What is Employee Age , please enter valid Age (18-60)" << std::endl;
				std::cin >> TempInt;
			} while (!(TempInt >= 18 && TempInt <= 60));
			i.SetAge(TempInt);
			std::cout << "-> What is Employee Designation" << std::endl;
			std::cin >> tempS;
			i.setDesignation(tempS);
			std::cout << "-> What is Employee Salary" << std::endl;
			std::cin >> TempInt;
			i.SetSalary(TempInt);

			std::cout << "Record Updated Succesffully"<<std::endl;
			Checkmate = 0;

		}
	}
	if (Checkmate == 1)
	{
		std::cout << "Record not Found, please make sure your ID was correct and try again from the menu" << std::endl;
	}
}

void AddInventoryItem(std::vector<Inventory>& Inv)
{
	char tempS[50];
	Inventory Temp;
	int TempInt;
	std::cout << "Enter the Name of the Item" << std::endl;
	std::cin>>tempS;
	Temp.SetItemName(tempS);
	std::cout << "Enter the ProductID of the Item, integers only" << std::endl;
	std::cin >> TempInt;
	Temp.SetItemID(TempInt);
	std::cout << "Enter the Price of the Item" << std::endl;
	std::cin >> TempInt;
	Temp.SetItemPrice(TempInt);
	Inv.push_back(Temp);
	std::cout << "Item Added Succesfully!" << std::endl;

}
void UpdateInventoryItem(std::vector<Inventory>& Inv)
{
	char tempS[50];
	Inventory Temp;
	int TempInt;
	int Checkmate = 1;
	std::cout << "Enter the Product ID" << std::endl;
	std::cin >> TempInt;
	for (auto& i : Inv)
	{
		if (i.GetItemID() == TempInt)
		{
			std::cout << "Item found, lets update it" << std::endl;

			std::cout << "Enter the Name of the Item" << std::endl;
			std::cin >> tempS;
			i.SetItemName(tempS);
			std::cout << "Enter the Price of the Item" << std::endl;
			std::cin >> TempInt;
			i.SetItemPrice(TempInt);
			std::cout << "Item Updated Succesfully!" << std::endl;
			Checkmate = 0;

		}
	}
	if (Checkmate == 1)
	{
		std::cout << "Product not Found, please make sure your ID was correct and try again from the menu" << std::endl;
	}
	
	
}
std::ostream& operator <<(std::ostream& out, const Employee& Emp)
{
	out << "Name = " << Emp.Getname() << "\t Age =" << Emp.GetAge() << "\t Salary =" << Emp.GetSalary() << "\t Designation =" << Emp.GetDesignation() << "\t EmployeeID =" << Emp.GetEmployeeid() << std::endl;
	return out;
}
void SearchEmp(std::vector<Employee>& Emp)
{
	std::string ID;
	int Checkmate = 1;
	std::cout << "Enter the Unique ID of the Employee you want to search from the vector (NO Spaces)" << std::endl;
	std::cin >> ID;
	for (auto& i : Emp)
	{
		if (i.GetEmployeeid() == ID)
		{
			std::cout << "Employee Details Are listed below" << std::endl;

			std::cout << i;
		}
	}
}


void SearchInv(std::vector<Inventory>&Inv)
{
	std::string tempS;
	Inventory Temp;
	int TempInt;
	int Checkmate = 1;
	std::cout << "Enter the Product ID" << std::endl;
	std::cin >> TempInt;
	for (auto& i : Inv)
	{
		if (i.GetItemID() == TempInt)
		{
			std::cout << "Item found" << std::endl;
			std::cout << i;

		}
	}
	if (Checkmate == 1)
	{
		std::cout << "Product not Found, please make sure your ID was correct and try again from the menu" << std::endl;
	}
}

void WriteBin(std::vector<Inventory>&Inv, std::vector<Employee>& Emp,std::string Filename)
{

	std::fstream f(Filename,std::ios::binary |  std::ios::out );
	if (f.is_open())
	{
		std::cout << "File opened Succesfully" << std::endl;
		int totalEmp = static_cast<int>(Emp.size());
		f.write((char*)&(Employee::TotalEmp), sizeof(int));
		for (auto &i : Emp)
		{    
			f.write((char*)&i, sizeof(Employee));
			
		}
		for (auto &j : Inv)
		{
			f.write((char*)&j, sizeof(Inventory));
			
		}
	}
	else
	{
		std::cout << "file could not be opened" << std::endl;
	}
	f.close();

	std::cout << "Records Saved Successfuly" << std::endl;

}
void ReadBin(std::vector<Inventory>&Inv, std::vector<Employee>& Emp,std::string Filename)
{
	Employee TempE;
	Inventory TempInv;
	char TempS[50];
	int i;
	
	std::fstream f(Filename, std::ios::binary | std::ios::in);
	if (f.is_open())
	{
		std::cout << "File opened Succesfully" << std::endl;
		f.read((char*)&i, sizeof(int));
		for (int j = 0; j < i-1; j++)
		{
			f.read((char*)&TempE, sizeof(Employee));
			Emp.push_back(TempE);
		}
										
			while (!f.eof())
			{
				f.read((char*)&TempInv, sizeof(Inventory));
				if (f.gcount() != 0)
				{
					Inv.push_back(TempInv);
				}
				
			}
		
		f.close();
		std::cout << "Records read Successfuly" << std::endl;

	}
	else
	{
		std::cout << "file could not be opened as it does not exists, we will create a new file for you , dont worry " << std::endl;
	}
	
}
void Displayinv(std::vector<Inventory>&Inv)
{
	std::cout << "Inventory Details Are listed below" << std::endl;

	for (auto &i : Inv)
	{
		std::cout << i;
	}
}
void DisplayRecords(std::vector<Inventory>&Inv,std::vector<Employee>& Emp1)
{
	std::cout << "All Records Are listed below" << std::endl;
	std::cout << "Inventory Records Are" << std::endl << std::endl;

	for (auto &i : Inv)
	{
		std::cout << i;
	}
	std::cout << "Employee Records Are" << std::endl << std::endl;

	for (auto &i : Emp1)
	{
		std::cout << i;
	}

}

void HeadManagerMenu(std::vector<Employee>& Emp1, std::vector<Inventory>&Inv)
{
	int Choice,x=1;
	do {
		std::cout << "Welcome to Head Manager Desk, Choose from the following Actions" << std::endl;
		std::cout << "1-Add New Employee" << std::endl;
		std::cout << "2-Update Employee Information" << std::endl;
		std::cout << "3-Add New Inventory Item" << std::endl;
		std::cout << "4-Update Any Inventory Item" << std::endl;
		std::cout << "5-Search Employee Data and Display" << std::endl;
		std::cout << "6-Display Inventory Data" << std::endl;
		std::cout << "7-Display All the Records at ONCE" << std::endl;
		std::cout << "8-Quit The Menu" << std::endl;

		std::cin >> Choice;
		switch (Choice)
		{
		case 1:
			AddEmploye(Emp1);
			break;
		case 2:
			UpdateEmp(Emp1);
			break;
		case 3:
			AddInventoryItem(Inv);
			break;
		case 4:
			UpdateInventoryItem(Inv);
			break;
		case 5:
			SearchEmp(Emp1);
			break;
		case 6:
			Displayinv(Inv);
			break;
		case 7:
			DisplayRecords(Inv, Emp1);
			break;
		case 8:
			x = 0;
			break;


		default:
			break;
	}

		
	} while (x);
	WriteBin(Inv, Emp1, "Records.bin");








}


int main(int argc,char* argv[])
{
	std::vector<Employee>Emp1;
	std::vector<Inventory>Inv;
	int Choice;
	int Passcode;
	int count ;
	std::string Filename;
	std::string Arg;
	if (argc == 3)
	{
		Arg = argv[1];
		Filename = argv[2];
	}
	if (argc == 2)
	{
		Arg = argv[1];

	}
	

	if (argc == 3 && (Arg == "Export" || Arg == "export"))
	{
		ReadBin(Inv, Emp1, "Records.bin");

		std::fstream data(Filename, std::ios::out);
		data << Emp1.size() << ",";
		for (auto &i : Emp1)
		{  
			data <<i.name<<","<< i.Age << "," << i.Designation << "," << i.EmployeID<<","<<i.Salary;
			data << ",";

		}
		data << Inv.size() << ",";

		for (auto &i : Inv)
		{
			data << i.Itemname<<","<<i.ProductID<<","<<i.Price;
			data << ",";

		}
		std::cout << "File Exported" << std::endl;


	}
	else if (argc == 3 && (Arg == "Import" || Arg == "import"))
	{
		char temp;
		std::string temp1;
		int num,records,records1;
		Employee i;
		Inventory In;
		ReadBin(Inv, Emp1, "Records.bin");


		std::fstream data(Filename, std::ios::in);

		std::getline(data, temp1, ',');
		records = std::stoi(temp1);
		std::cout << "Number of Employee records: " << records << std::endl;

		for (int j = 0; j < records; j++)
		{
			std::getline(data, temp1, ',');
			std::cout << temp1;
			strncpy_s(i.name, temp1.c_str(), sizeof(i.name) - 1);

			std::getline(data, temp1, ',');
			std::cout << temp1;

			num = std::stoi(temp1);
			i.Age = num;

			std::getline(data, temp1, ',');
			std::cout << temp1;

			strncpy_s(i.Designation, temp1.c_str(), sizeof(i.Designation) - 1);

			std::getline(data, temp1, ',');
			std::cout << temp1;
			strncpy_s(i.EmployeID, temp1.c_str(), sizeof(i.EmployeID) - 1);

			std::getline(data, temp1, ',');
			std::cout << temp1;
			num = stoi(temp1);
			i.Salary = num;
			Emp1.push_back(i);
		}

			
		std::getline(data, temp1, ',');
		records1 = std::stoi(temp1);
		std::cout << "Number of inv records: " << records1 << std::endl;


		for(int i=0;i<records1;i++)
		{
			std::getline(data, temp1, ',');
			strncpy_s(In.Itemname, temp1.c_str(), sizeof(In.Itemname) - 1);

			std::getline(data, temp1, ',');
			num = std::stoi(temp1);
			In.ProductID = num;

			std::getline(data, temp1, ',');
			num = std::stoi(temp1);
			In.Price = num;

			Inv.push_back(In);
		}

		std::cout << "File Imported" << std::endl;
		std::cout << "Imported Records Are" << std::endl;
		DisplayRecords(Inv, Emp1);
		WriteBin(Inv, Emp1,"Records.bin");
	}
	else if (argc == 2 && (Arg == "Help" || Arg == "help"))
	{
		std::cout << "The Program consists of multiple employee and inventory record adding/updating/searching options, however these actions are limited" << std::endl <<
			"to the head of the store Only, the password for login is 1111 " << std::endl
			<< "2-while giving the file name, please add the extention with the name as well, ie data.bin" << std::endl
			<< "3-The program automatically saves the file into binary form when the program ends" << std::endl;
	}
	
	else if (argc == 1)
	{
	
		ReadBin(Inv, Emp1, "Records.bin");


		std::cout << "Welcome to Computer Store, please choose from the following Actions " << std::endl;
		std::cout << "1- Login as Head Manager (only Manager can update/Add/Delete inventory or Employee Records" << std::endl;
		std::cout << "2- View Employee and Company Sales records" << std::endl;
		std::cout << "Data will automatically be stored once the program ends, dont worry!" << std::endl;
		do {
			std::cout << "Please choose 1 or 2" << std::endl;
			std::cin >> Choice;

		} while (!(Choice == 1 || Choice == 2));

		switch (Choice)
		{
		case 1:
			count = 3;
			do {
				std::cout << "Please Enter Correct Pin (it is 1111) , you have " << count-- << " Tries left " << std::endl;
				std::cin >> Passcode;
			} while (Passcode != 1111 && count > 0);

			if (Passcode == 1111)
			{
				std::cout << "Correct Pin, Access Granted" << std::endl;
				HeadManagerMenu(Emp1, Inv);
			}
			else
			{
				std::cout << "Out of Tries, you cannot gain access " << std::endl;
			}
			break;
		case 2:
			DisplayRecords(Inv, Emp1);
			break;


		default:
			break;
		}
	}
	


}