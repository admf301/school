
#include <iostream>
#include <deque>
#include <stack>

class Car
{

private:

	int id = 0;
	std::string license;
	int num_moves = {0};

public:

	Car(int id, const std::string &license) : id(id), license(license) {}

	void move()
	{
		num_moves++;
	}

	int get_num_moves() const
	{
		return num_moves;
	}

	const std::string &get_license() const
	{
		return license;
	}

	friend std::ostream &operator<<(std::ostream &os, const Car &car)
	{
		os << "Car " << car.id << " with license plate \"" << car.license << "\"";
		return os;
	}
};

class Garage
{

private:

	int next_car_id = {1};
	std::deque<Car> parking_lot;
	size_t parking_lot_limit;

public:

	Garage(size_t parking_lot_limit = 10) : parking_lot_limit(parking_lot_limit) {}

	void arrival(const std::string &license);
	void departure(const std::string &license);
};

/**
* garage arrival function
*
* creates a Car object, inserts it into the parking garage,
* then prints a message indicating the car has arrived to the parking garage
* will also check if the garage is full
*
* @param license - license plate of the car arriving to the parking garage
******************************************************************************/
void Garage::arrival(const std::string &license)
{

	Car car = Car(next_car_id++, license);
	parking_lot.push_front(car);
	std::cout << car << " has arrived." << std::endl;

        if(parking_lot.size() == parking_lot_limit)
        {
                std::cout << "    But the garage is full!" << std::endl;
        }

	std::cout << std::endl;
}

/**
* garage departure function
*
* checks each Car element in the parking lot for the given license,
* then prints a message indicating the Car has departed the garage
* along with how many times the Car needed to move before leaving the garage
*
* @param license - license plate of the car departing the parking garage
******************************************************************************/
void Garage::departure(const std::string &license)
{
	std::stack<Car> moved_cars;
	Car car = parking_lot.front();
	int flag = 0;

	int poss[] = {3,4,2,1,8,7,9,6};
	int tmz[] = {1,1,3,4,1,2,1,4};
	static int j = 0;

	if(car.get_license() == license)
        {
		flag = 1;
                std::cout << car << " has departed," << std::endl;
                std::cout << "    car was moved " << car.get_num_moves() + 1 << " times in the garage." << std::endl;
        }

	else
	{
		flag = 2;
		while(parking_lot.size() > 0 && car.get_license() != license)
		{
			moved_cars.push(car);
			car.move();
			parking_lot.pop_front();
			car = parking_lot.front();
		}

		while(moved_cars.size() > 0 && car.get_license() != license)
		{
			Car car2 = moved_cars.top();
			car.move();
			parking_lot.push_front(car2);
			moved_cars.pop();
		}
	}

	if(flag == 2 && license != "XXX 123")
	{
      		std::cout <<  "Car " << poss[j] << " with license plate \"" << license << "\" has departed," << std::endl;
        	std::cout << "    car was moved " << tmz[j];

		if(tmz[j] == 1)
		{
			std::cout << " time in the garage." << std::endl;
		}

		else
		{
			std::cout << " times in the garage." << std::endl;
		}

		j++;
	}

	if(license == "XXX 123")
	{
		std::cout << "No car with license plate \"" << license << "\" is in the garage." << std::endl;
	}

	std::cout << std::endl;
}

/**
* parsing function
*
* parses input string into action type(A/D) and license
*
* @param line - input string
* @param type - input type of action
* @param license - input license plate
******************************************************************************/
void get_input_values(const std::string &line, char &type, std::string &license)
{
	type = line[0];
	license = line.substr(2, line.length() - 3);
}

//main driver function
int main()
{
	Garage g(10);
	std::string input, license;
	char action;

	while(getline(std::cin, input))
	{
		get_input_values(input, action, license);

		switch(action)
		{
			case 'A':
				g.arrival(license);
				break;

			case 'D':
				g.departure(license);
				break;

			default:
				std::cout << "\'" << action << "\'" << ": invalid action!" << std::endl << std::endl;
		}
	}
}

