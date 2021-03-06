#include <iostream>
#include <string.h>
#include <vector>
#include <sstream>
using namespace std;


class Head
{
	protected:
		string part_name;
		int part_num;
		int weight;
		double cost;
		string description;
	public:
		Head(string part_name, int part_num, int weight, double cost, string description);
		double get_price();
		string to_string();
};

Head::Head(string part_name, int part_num, int weight, double cost, string description)
{
	this->part_name = part_name;
	this->part_num = part_num;
	this->weight = weight;
	this->cost = cost;
	this->description = description;
}

double Head::get_price()
{
	return cost;
}

string Head::to_string()
{
	stringstream to_string;
	to_string << "#" << part_num << " " << part_name << "\nWeight: " << weight << " kg\n
	Cost: $" << cost << "\nDescription: " << description << "\n\n";
	return to_string.str();
}

class Arm
{
	protected:
		string part_name;
		int part_num;
		int weight;
		double cost;
		int power_usage;
		string description;
	public:
		Arm(string part_name, int part_num, int weight, double cost, int power_usage, string description);
		double get_price();
		string to_string();
};

Arm::Arm(string part_name, int part_num, int weight, double cost, int power_usage, string description)
{
	this->part_name = part_name;
	this->part_num = part_num;
	this->weight = weight;
	this->cost = cost;
	this->power_usage = power_usage;
	this->description = description;
}

double Arm::get_price()
{
	return cost;
}

string Arm::to_string()
{
	stringstream to_string;
	to_string << "#" << part_num << " " << part_name << "\nWeight: " << weight << " kg\nPower Consumed by Part[watts]: " << power_usage << "\nCost: $" << cost << "\nDescription: " << description << "\n\n";
	return to_string.str();
}

class Battery
{
	protected:
		string part_name;
		int part_num;
		int power_stored;
		int weight;
		double cost;
		string description;
	public:
		Battery(string part_name, int part_num, int power_stored, int weight, double cost, string description);
		int get_power_stored();
		int get_weight();
		double get_price();
		string to_string();
};

Battery::Battery(string part_name, int part_num, int power_stored, int weight, double cost, string description)
{
	this->part_name = part_name;
	this->part_num = part_num;
	this->power_stored = power_stored;
	this->weight = weight;
	this->cost = cost;
	this->description = description;
}

double Battery::get_price()
{
	return cost;
}

int Battery::get_power_stored()
{
	return power_stored;
}

int Battery::get_weight()
{
	return weight;
}

string Battery::to_string()
{
	stringstream to_string;
	to_string << "#" << part_num << " " << part_name << "\nWeight: " << weight << " kg\nPower Avaliable: " << power_stored << "\nCost: $" << cost << "\nDescription: " << description << "\n\n";
	return to_string.str();
}

class Torso
{
	protected:
		string part_name;
		int part_num;
		int weight;
		int battery_num;
		int count;
		double cost;
		vector<Battery> batteries;
		string description;
	public:
		Torso(string part_name, int part_num, int weight, int battery_num, double cost, string description);
		void add_battery(Battery battery);
		int get_total_power();
		double get_total_cost();
		int get_total_weight();	
		int get_battery_count();
		double get_price();
		string to_string();
};

Torso::Torso(string part_name, int part_num, int weight, int battery_num, double cost, string description)
{
	this->part_name = part_name;
	this->part_num = part_num;
	this->weight = weight;
	this->battery_num = battery_num;
	this->cost = cost;
	this->description = description;
	count = 0;
}

double Torso::get_price()
{
	double total_price = 0;
	for(int i = 0; i < batteries.size(); i++)
	{
		total_price = total_price + batteries[i].get_price();
	}
	total_price = total_price + cost;
	return total_price;
}

void Torso::add_battery(Battery battery)
{
	if(count <= battery_num)
	{
		batteries.push_back(battery);
		count++;
	}
	else
	{
		cout << "Max Battery Count Reached!";
	}
}

int Torso::get_total_power()
{
	int total_power = 0;
	for(int i = 0; i < batteries.size(); i++)
	{
		total_power = total_power + batteries[i].get_power_stored();

	}
	return total_power;
}

int Torso::get_total_weight()
{
	int total_weight;
	for(int i = 0; i < batteries.size(); i++)
	{
		total_weight = total_weight + batteries[i].get_weight();
	}
	total_weight = total_weight + weight;
	return total_weight;
}

int Torso::get_battery_count()
{
	return battery_num;
}

string Torso::to_string()
{
	stringstream to_string;
	to_string << "#" << part_num << " " << part_name << "\nWeight: " << weight << " kg\n# of Battery Compartments: " << battery_num << "\nCost: $" << cost << "\nDescription: " << description << "\n\n";
	return to_string.str();
}

class Locomotor
{
	protected:
		string part_name;
		int part_num;
		int weight;
		double cost;
		int power_consumed;
		int max_speed;
		string description;
	public:
		Locomotor(string part_name, int part_num, int weight, double cost, int power_consumed, int max_speed, string description);
		double get_price();
		string to_string();
};

Locomotor::Locomotor(string part_name, int part_num, int weight, double cost, int power_consumed, int max_speed, string description)
{
	this->part_name = part_name;
	this->part_num = part_num;
	this->weight = weight;
	this->cost = cost;
	this->power_consumed = power_consumed;
	this->max_speed = max_speed;
	this->description = description;
}

double Locomotor::get_price()
{
	return cost;
}

string Locomotor::to_string()
{
	stringstream to_string;
	to_string << "#" << part_num << " " << part_name << "\nWeight: " << weight << " kg\nPower Consumed by Part(watts): " << power_consumed << "\nMax Speed: " << max_speed << " mph" <<"\nCost: $" << cost << "\nDescription: " << description << "\n\n";
	return to_string.str();
}


class Robot
{
	protected:
		int model_number;
		string model_name;
		double model_price;
		Head* head;
		Torso* torso;
		Arm* arm_left;
		Arm* arm_right;
	    Locomotor* locomotor;
	public:
		Robot(Head head, Torso torso, Arm left, Arm right,Locomotor locomotor,string model_name);
		double get_model_price();
		string to_string();
		void test_interface();
		void clean();
};

Robot::Robot(Head head, Torso torso, Arm left, Arm right,Locomotor locomotor,string model_name)
{
	this->head = &head;
	this->torso = &torso;
	this->arm_left = &left;
	this->arm_right = &right;
	this->locomotor = &locomotor;
	this->model_name = model_name;
}

double Robot::get_model_price()
{
	double model_price = 0;
	double profit_margin = 0;
	model_price = head->get_price() + torso->get_price() + arm_left->get_price() + arm_right->get_price() + locomotor->get_price();
	profit_margin = (model_price * .20);
	model_price = model_price + profit_margin;
	return model_price;
}

string Robot::to_string()
{
	stringstream to_string;
	to_string << model_name << "\nPrice: " << get_model_price();
	return to_string.str();
}

class System
{
	private:
		vector<Robot> list_of_robots;
		vector<Head> list_of_heads;
		vector<Arm> list_of_arms;
		vector<Torso> list_of_torsos;
		vector<Locomotor> list_of_locomotors;
		vector<Battery> list_of_batteries;
	public:
		void add_head();
		void add_arm();
		void add_torso();
		void add_locomotor();
		void add_battery();
		void create_robot();
		void view_robots();
		void test_interface();
		void clean();
};

void System::test_interface()
{
	int input;
	string interface = R"(
    **************************
    *                        *
    *    1) Add Head         *
    *    2) Add Arm          *
    *    3) Add Torso        *
    *    4) Add Locomotor    *
    *    5) Add Battery      *
    *    6) Create Robot     *
    *    7) View Robot       *
    *    8) Exit             *
    *                        *
    **************************

    Option: )";
	cout << interface;
	//cin >> input;

	while (!(cin >> input) || (input < 0 || input > 8) ) // <<< note use of "short circuit" logical operation here
	{
	    cout << "Enter valid option: ";
	    cin.clear();
	    cin.ignore(INT_MAX, '\n'); // NB: preferred method for flushing cin
	}

	if(input == 1)
	{
		clean();
		add_head();
	}
	else if(input == 2)
	{
		clean();
		add_arm();
	}
	else if(input == 3)
	{
		clean();
		add_torso();
	}
	else if(input == 4)
	{
		clean();
		add_locomotor();
	}
	else if(input == 5)
	{
		clean();
		add_battery();
	}
	else if(input == 6)
	{
		clean();
		create_robot();
	}
	else if(input == 7)
	{
		clean();
		view_robots();
	}
	else if(input == 8)
	{
		cout << "\n\nExiting...\n";
		exit(0);
	}
	else
	{
		cout << "\n\nExiting...\n";
		exit(0);
	}
}

void System::create_robot()
{
	int input_head;
	if(list_of_heads.size() == 0)
	{
		clean();
		cout << "No heads available.\n";
		test_interface();
	}
	else
	{
		for(int i = 0; i < list_of_heads.size(); i++)
		{
			cout << list_of_heads[i].to_string();
		}
	}
	cout << "\nSelect a Head (Part #): ";
	
	while (!(cin >> input_head) || input_head < 0) // <<< note use of "short circuit" logical operation here
	{
	    cout << "Please input a valid part number.";
	    cin.clear();
	    cin.ignore(INT_MAX, '\n'); // NB: preferred method for flushing cin
	}
	clean();

	int input_torso;
	if(list_of_torsos.size() == 0)
	{
		clean();
		cout << "No torsos available.\n";
		test_interface();
	}
	else
	{
		for(int i = 0; i < list_of_torsos.size(); i++)
		{
			cout << list_of_torsos[i].to_string();
		}
	}
	cout << "\nSelect a Torso (Part#)";
	
	while (!(cin >> input_torso) || input_torso < 0) // <<< note use of "short circuit" logical operation here
	{
	    cout << "Input valid parts number: ";
	    cin.clear();
	    cin.ignore(INT_MAX, '\n'); // NB: preferred method for flushing cin
	}
	clean();

	int input_batteries[3];
	if(list_of_batteries.size() == 0)
	{
		clean();
		cout << "No batteries available.\n";
		test_interface();
	}
	else
	{
		for(int i = 0; i < list_of_torsos[input_torso].get_battery_count(); i++)
		{
			for(int x = 0; x < list_of_batteries.size(); x++)
			{
				cout << list_of_batteries[x].to_string();
			}
			cout << "\nSelect Battery [#" << (i+1) << "]: ";
			
			while (!(cin >> input_batteries[i]) || input_batteries[i] < 0) // <<< note use of "short circuit" logical operation here
			{
			    cout << "Input valid battery number: ";
			    cin.clear();
			    cin.ignore(INT_MAX, '\n'); // NB: preferred method for flushing cin
			}
			clean();
		}
	}
	for(int i = 0; i < list_of_torsos[input_torso].get_battery_count(); i++)
	{
		list_of_torsos[input_torso].add_battery(list_of_batteries[input_batteries[i]]);
	}

	int input_left_arm;
	if(list_of_arms.size() == 0)
	{
		clean();
		cout << "No arms available.";
		test_interface();
	}
	else
	{
		for(int i = 0; i < list_of_arms.size(); i++)
		{
			cout << list_of_arms[i].to_string();
		}
	}
	cout << "\nSelect a Left Arm [Part #]: ";
	
	while (!(cin >> input_left_arm) || input_left_arm < 0) // <<< note use of "short circuit" logical operation here
	{
	    cout << "Input valid part number: ";
	    cin.clear();
	    cin.ignore(INT_MAX, '\n'); // NB: preferred method for flushing cin
	}
	clean();

	int input_right_arm;
	if(list_of_arms.size() == 0)
	{
		clean();
		cout << "No arms available.";
		test_interface();
	}
	else
	{
		for(int i = 0; i < list_of_arms.size(); i++)
		{
			cout << list_of_arms[i].to_string();
		}
	}
	cout << "\nSelect a Right Arm [Part #]: ";
	
	while (!(cin >> input_right_arm) || input_right_arm < 0) // <<< note use of "short circuit" logical operation here
	{
	    cout << "Input valid part number: ";
	    cin.clear();
	    cin.ignore(INT_MAX, '\n'); // NB: preferred method for flushing cin
	}
	clean();

	int input_locomotor;
	if(list_of_locomotors.size() == 0)
	{
		clean();
		cout << "No locomotors available.";
		test_interface();
	}
	else
	{
		for(int i = 0; i < list_of_locomotors.size(); i++)
		{
			cout << list_of_locomotors[i].to_string();
		}
	}
	cout << "\nSelect a Locomotor: ";
	
	while (!(cin >> input_locomotor) || input_locomotor < 0) // <<< note use of "short circuit" logical operation here
	{
	    cout << "Select valid Locomotor: ";
	    cin.clear();
	    cin.ignore(INT_MAX, '\n'); // NB: preferred method for flushing cin
	}
	clean();

	string model_name;
	cout << "Model Name: ";
	getline(cin,model_name);
	getline(cin,model_name);

	Robot robot(list_of_heads[input_head], list_of_torsos[input_torso], list_of_arms[input_left_arm], list_of_arms[input_right_arm], list_of_locomotors[input_locomotor],model_name);
	list_of_robots.push_back(robot);
	cout << "";
	clean();
	test_interface();
}

void System::view_robots()
{
	cout << "List of Robots:\n\n";
	for(int i = 0; i < list_of_robots.size(); i++)
	{
		cout << list_of_robots[i].to_string() << "\n";
	}
	test_interface();
}

void System::clean()
{
	for(int i; i < 200; i++)
	{
		cout << "\n";
	}
}

void System::add_head()
{
	string part_name;
	cout << "Name of Part: ";
	getline(cin,part_name);
	getline(cin,part_name);

	int part_num = list_of_heads.size();
	int weight;

	cout << "Weight of Part (kg): ";
	
	while (!(cin >> weight) || weight < 0) // <<< note use of "short circuit" logical operation here
	{
	    cout << "Select valid Locomotor: ";
	    cin.clear();
	    cin.ignore(INT_MAX, '\n'); // NB: preferred method for flushing cin
	}
	
	double cost;
	cout << "Price of Part: ";
	
	while (!(cin >> cost) || cost < 0) // <<< note use of "short circuit" logical operation here
	{
	    cout << "Select valid Locomotor: ";
	    cin.clear();
	    cin.ignore(INT_MAX, '\n'); // NB: preferred method for flushing cin
	}
	
	string description;
	cout << "Description of Part: ";
	getline(cin,description);
	getline(cin,description);
	
	Head head(part_name, part_num, weight, cost, description);
	list_of_heads.push_back(head);
	cout << "";
	
	clean();
	test_interface();
}

void System::add_arm()
{
	string part_name;
	cout << "Name of Part: ";
	getline(cin,part_name);
	getline(cin,part_name);
	
	int part_num = list_of_arms.size();
	int weight;
	cout << "Weight of Part (kg): ";
	
	while (!(cin >> weight) || weight < 0) // <<< note use of "short circuit" logical operation here
	{
	    cout << "Select valid Locomotor: ";
	    cin.clear();
	    cin.ignore(INT_MAX, '\n'); // NB: preferred method for flushing cin
	}
	
	double cost;
	cout << "Price of part: $";
	
	while (!(cin >> cost) || cost < 0) // <<< note use of "short circuit" logical operation here
	{
	    cout << "Select valid Locomotor: ";
	    cin.clear();
	    cin.ignore(INT_MAX, '\n'); // NB: preferred method for flushing cin
	}
	
	int power_usage;
	cout << "Power Consumed by Part (watts): ";
	
	while (!(cin >> power_usage) || power_usage < 0) // <<< note use of "short circuit" logical operation here
	{
	    cout << "Select valid Locomotor: ";
	    cin.clear();
	    cin.ignore(INT_MAX, '\n'); // NB: preferred method for flushing cin
	}
	
	string description;
	cout << "Description of Part: ";
	getline(cin,description);
	getline(cin,description);
	
	Arm arm(part_name, part_num, weight, cost, power_usage, description);
	list_of_arms.push_back(arm);
	cout << "";
	clean();
	test_interface();
}

void System::add_torso()
{
	string part_name;
	cout << "Name of Part: ";
	getline(cin,part_name);
	getline(cin,part_name);

	int part_num = list_of_torsos.size();
	
	int weight;
	cout << "Weight of Part (kg): ";
	
	while (!(cin >> weight) || weight < 0) // <<< note use of "short circuit" logical operation here
	{
	    cout << "Select valid Locomotor: ";
	    cin.clear();
	    cin.ignore(INT_MAX, '\n'); // NB: preferred method for flushing cin
	}
	
	int battery_num;
	cout << "Number of Battery Compartments: ";
	
	while (!(cin >> battery_num) || battery_num < 0) // <<< note use of "short circuit" logical operation here
	{
	    cout << "Select valid Locomotor: ";
	    cin.clear();
	    cin.ignore(INT_MAX, '\n'); // NB: preferred method for flushing cin
	}
	
	double cost;
	cout << "Price of part: ";
	
	while (!(cin >> cost) || cost < 0) // <<< note use of "short circuit" logical operation here
	{
	    cout << "Select valid Locomotor: ";
	    cin.clear();
	    cin.ignore(INT_MAX, '\n'); // NB: preferred method for flushing cin
	}
	
	string description;
	cout << "Description of Part: ";
	getline(cin,description);
	getline(cin,description);
	
	Torso torso(part_name, part_num, weight, battery_num, cost, description);
	list_of_torsos.push_back(torso);
	cout << "";
	
	clean();
	test_interface();
}

void System::add_locomotor()
{
	string part_name;
	cout << "Name of Part: ";
	getline(cin,part_name);
	getline(cin,part_name);
	int part_num = list_of_locomotors.size();
	
	double weight;
	cout << "Weight of Part (kg): ";
	
		while (!(cin >> weight) || weight < 0) // <<< note use of "short circuit" logical operation here
	{
	    cout << "Please input valid weight: ";
	    cin.clear();
	    cin.ignore(INT_MAX, '\n'); // NB: preferred method for flushing cin
	} 
	
	double cost;
	cout << "Price of part: ";
	
		while (!(cin >> cost) || cost < 0) // <<< note use of "short circuit" logical operation here
	{
	    cout << "Please input valid price: ";
	    cin.clear();
	    cin.ignore(INT_MAX, '\n'); // NB: preferred method for flushing cin
	}
	
	int power_consumed;
	cout << "Power Consumed by Part (watts): ";
	
			while (!(cin >> power_consumed) || power_consumed < 0) // <<< note use of "short circuit" logical operation here
	{
	    cout << "Please input valid power consumption: ";
	    cin.clear();
	    cin.ignore(INT_MAX, '\n'); // NB: preferred method for flushing cin
	}
	
	int max_speed;
	cout << "Max Speed (mph): ";
	
			while (!(cin >> max_speed) || max_speed < 0) // <<< note use of "short circuit" logical operation here
	{
	    cout << "Please input valid speed: ";
	    cin.clear();
	    cin.ignore(INT_MAX, '\n'); // NB: preferred method for flushing cin
	}
	string description;
	cout << "Description of Part: ";
	getline(cin,description);
	getline(cin,description);
	
	Locomotor locomotor(part_name, part_num, weight, cost, power_consumed, max_speed, description);
	list_of_locomotors.push_back(locomotor);
	cout << "";
	clean();
	test_interface();
}

void System::add_battery()
{
	string part_name;
	cout << "Name of Part: ";
	getline(cin,part_name);
	getline(cin,part_name);
	int part_num = list_of_batteries.size();
	
	int power_stored;
	cout << "Amount of Stored Power (kilowatt hours): ";
	cin >> power_stored;
	
	int weight;
	cout << "Weight of Part (kg): ";

	while (!(cin >> weight) || weight < 0) // <<< note use of "short circuit" logical operation here
	{
	    cout << "Please input valid weight: ";
	    cin.clear();
	    cin.ignore(INT_MAX, '\n'); // NB: preferred method for flushing cin
	}
	double cost;
	cout << "Price of part: ";
	
	while (!(cin >> cost) || cost < 0) // <<< note use of "short circuit" logical operation here
	{
	    cout << "Please input valid price: ";
	    cin.clear();
	    cin.ignore(INT_MAX, '\n'); // NB: preferred method for flushing cin
	}
	string description;
	cout << "Description of Part: ";
	getline(cin,description);
	getline(cin,description);
	
	Battery battery(part_name, part_num, power_stored, weight, cost, description);
	list_of_batteries.push_back(battery);
	cout << "";
	
	clean();
	test_interface();
}

int main()
{
	System test;
    test.test_interface();
	return 0;
}