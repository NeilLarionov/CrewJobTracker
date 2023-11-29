#include <iostream>
#include "Crew.h"
#include "Jobs.h"
#include <memory>
#include <cctype>

void displayStart();
void displayMenu();
void displayCrewJobs(std::unique_ptr<Crew>&);
bool displayOpenJobs(std::vector<std::unique_ptr<Jobs>>&);
void displayCrews(std::vector<std::unique_ptr<Crew>>&, std::vector<std::shared_ptr<Community>>&,
std::vector<std::unique_ptr<Jobs>>&);
void displayCommunityList(std::vector<std::shared_ptr<Community>>&);
void createNewCrew(std::vector<std::unique_ptr<Crew>>&);
void createNewCommunity(std::vector<std::shared_ptr<Community>>&);
void createNewJob(std::vector<std::unique_ptr<Jobs>>&, std::vector<std::shared_ptr<Community>>&);
void assignHouseToCrew(std::unique_ptr<Crew>&, std::vector<std::unique_ptr<Jobs>>&);
void manageJobs(std::vector<std::unique_ptr<Jobs>>&, std::vector<std::shared_ptr<Community>>&);
void editCrewName(std::unique_ptr<Crew>&);
void editCommunityList(std::vector<std::shared_ptr<Community>>&);
void editCommunityName(std::shared_ptr<Community>&);
void deleteCommunity(std::shared_ptr<Community>&);
void deleteCrew(std::unique_ptr<Crew>&);
bool confirm();
char getInput();
void moveJob(std::vector<std::unique_ptr<Jobs>>&, Crew&);



int main()
{
	bool quit{false};
	std::vector<std::unique_ptr<Crew>> crewList;
	std::vector<std::shared_ptr<Community>> communityList;
	std::vector<std::unique_ptr<Jobs>> openJobs;
	
	
	do{
//		displayStart();
		displayMenu();
		switch (getInput())
		{
			case '1':
				displayCrews(crewList, communityList, openJobs);
				//createNewCrew(crewList);
				break;
			case '2':
				manageJobs(openJobs,communityList);
				system("pause");
				break;
//			case '3':
//				displayCrews(crewList, communityList, openJobs);
//				break;
//			case '4':
//				createNewCommunity(communityList);
//				break;
//			case '5':
//				displayCommunityList(communityList);
//				break;
			case 'X':
				quit = true;
		}
	}while (!quit);
	
}

void displayStart()
{
	std::cout << "Welcome to the Siding Crew Tracker!" << std::endl;
}

void displayMenu()
{
	system("cls");
	std::cout << "1 - Manage Crews" << std::endl;
	std::cout << "2 - Manage Jobs" << std::endl;
//	std::cout << "3 - Display all crews" << std::endl;
//	std::cout << "4 - Create a new Community" << std::endl;
//	std::cout << "5 - Display list of Communities" << std::endl;
	std::cout << "\n\nX - Quit" << std::endl;
}

void createNewCrew(std::vector<std::unique_ptr<Crew>> &vec)
{
	system("cls");
	std::string name;
	
	std::cout << "Enter Name of lead crew member: ";
	std::cin.ignore();
	std::getline(std::cin, name);
	
	name.at(0) = toupper(name.at(0));
	
	for (const auto &crew: vec)
	{
		if (crew->getName() == name)
		{
			std::cout << "Crew already exists!" << std::endl;
			system("pause");
			return;
		}
	}
	
	std::unique_ptr<Crew> crew = std::make_unique<Crew>(name);
	vec.push_back(std::move(crew));
}

char getInput()
{
	char input{};
	std::cin >> input;
	input = toupper(input);
	return input;
	
}

void displayCrews(std::vector<std::unique_ptr<Crew>> &vec, std::vector<std::shared_ptr<Community>>& comVec,
	std::vector<std::unique_ptr<Jobs>>& jobsVec)
{
	system("cls");
	int count{1};
	int vecSize = vec.size();
	if (vecSize > 0) // Check if vector has any crews added
	{
		for (const auto &crew:vec) // loop through vector and print crews
		{
			std::cout << count << " - " << *crew << " - Jobs: " << crew->getNumJobs() << std::endl;
			count++;
		}   
		char crew;
		int num;
		do{
			std::cout << "\nN - Create new crew" << std::endl;
			std::cout << "X - Go back" << std::endl;
			std::cout << "\nSelect number of crew: ";
			crew = getInput();
		
			if (crew == 'X')
				return;
			else if (crew == 'N')
			{
				createNewCrew(vec);
				return;
			}
			num = crew - '0';
			
		
		}while(num <= 0 || num > vecSize);
	
		num--;
		bool valid{false};
		char input{};
		do{ //Menu for individual selected crew
			system("cls");
			std::cout << vec.at(num)->getName() << " - Jobs: " << vec.at(num)->getNumJobs() << std::endl << std::endl;
			std::cout << "1 - Assign job" << std::endl;
			std::cout << "2 - view jobs" << std::endl;
			std::cout << "3 - Edit crew name" << std::endl;
			std::cout << "4 - Delete crew" << std::endl;
			std::cout << "X - Go back" << std::endl;
		
			std::cin.clear();
			input = getInput();
			if (input == '1'|| input == '2' || input == '3' || input == 'X')
				valid = true;
			
		}while(!valid);
		switch (input)
		{
			case 'X': // Go back
				return;
			case '1': // Assign Job
				assignHouseToCrew(vec.at(num), jobsVec);
				break;
			case '2': // View jobs
				displayCrewJobs(vec.at(num));
				break;
			case '3': // Edit crew name
				editCrewName(vec.at(num));
				break;
			case '4': // Delete crew
				if (confirm())
				{
					vec.at(num).reset();
					vec.erase(vec.begin()+num);
				}
				break;
		}
		
	}
	else
	{
		std::cout << "There are no crews in list!" << std::endl;
		char input{};
		std::cout << "\nCreate new crew? (Y/N): ";
		std::cin >> input;
		if (toupper(input) == 'Y')
			createNewCrew(vec);
	}
		
	
	system("pause");
}

void createNewCommunity(std::vector<std::shared_ptr<Community>>& vec)
{
	std::string communityName{};
	std::cin.clear();
	std::cout << "What is the name of the community: ";
	//std::getline(std::cin, communityName);
	
	std::cin.ignore();
	std::getline(std::cin, communityName);
	communityName.at(0) = toupper(communityName.at(0));
	
	
	for (const auto &ptr:vec) // Loop through vector 
	{
		if (ptr->getName() == communityName) // compare new name to names in vector
		{
			std::cout << "This community already exists!" << std::endl;
			return;
		}
		std::cout << ptr->getName();
	}
	
	std::shared_ptr<Community> com = std::make_shared<Community>(communityName);
	vec.push_back(com);
}

void displayCommunityList(std::vector<std::shared_ptr<Community>>& vec)
{
	int count{1};
	
	system("cls");
	if (vec.size() > 0)
	{
	
		for (const auto &com:vec)
		{
			std::cout << count << " - " << com->getName() << std::endl;
			count++;
		}
	}
	else
		std::cout << "No communities currently in list!" << std::endl;
}

void assignHouseToCrew(std::unique_ptr<Crew>& crew, std::vector<std::unique_ptr<Jobs>>& jobsVec)
{
	system("cls");
	if (displayOpenJobs(jobsVec))
	{
		int input{};
		int jobsVecSize = jobsVec.size();
		std::cout << "Select the number of the job you wish to assign to this crew: ";
		std::cin >> input;
		bool valid{false};
		do{
			if (input <= 0 || input > jobsVecSize)
			{
				std::cout << "Not a valid selection. . .Try again: ";
				std::cin >> input;
			}
			else
			{
				valid = true;
				input--;
			}
		}while(!valid);
		
		crew->assignHouse(jobsVec.at(input));
		
		jobsVec.at(input).reset();
		jobsVec.erase(jobsVec.begin()+input);
		
		std::cout << "Job was assigned successfully!" << std::endl;
	}
}
void editCrewName(std::unique_ptr<Crew>& crew)
{
	system("cls");
	std::string name{};
	std::cout << "Enter a new name for this crew: ";
	std::cin.ignore();
	std::getline(std::cin, name);
	name.at(0) = toupper(name.at(0));
	
	crew->setName(name);
}

void deleteCrew(std::unique_ptr<Crew>& crew)
{
	crew.reset();
}

bool confirm()
{
	char input{};
	std::cout << "Are you sure? (Y/N): ";
	std::cin >> input;
	if (toupper(input) == 'Y')
		return true;
	
	return false;
	
}

void manageJobs(std::vector<std::unique_ptr<Jobs>> &openJobsVec, std::vector<std::shared_ptr<Community>> &comVec)
{
	system("cls");
	std::cout << "There are currently: " << openJobsVec.size() << " unassigned jobs." << std::endl << std::endl;
	char input{};
	bool valid{false};
	do{
		std::cout << "1 - View unassigned jobs." << std::endl;
		std::cout << "2 - Create new job." << std::endl;
		std::cout << "3 - Edit Community" << std::endl;
		std::cout << "X - Go back." << std::endl;
		input = getInput();
		if (input != '1' || input != '2' || input != '3' ||input != 'X')
			valid = true;
	}while(!valid);
	
	switch(input)
	{
		case 'X':
			return;
			break;
		case '1':
			displayOpenJobs(openJobsVec);
			break;
		case '2':
			createNewJob(openJobsVec, comVec);
			break;
		case '3':
			editCommunityList(comVec);
			
			
	}
}

void displayCrewJobs(std::unique_ptr<Crew>& crew)
{
	system("cls");
	int count{1};
	std::cout << " -- " << crew->getName() << " --" << std::endl << std::endl;
	for (const auto &crewJob: crew->getJobVec())
	{
	
		std::cout << count << " - " << crewJob->com.getName() << " Lot: " << crewJob->getLotNumber() << std::endl;
		count++;
	}
}
		
bool displayOpenJobs(std::vector<std::unique_ptr<Jobs>>& vec)
{
	int count{1};
	if (vec.size() > 0)
	{
		for (const auto &job : vec)
		{
			std::cout << count << " - " << job->com.getName() << " Lot: " << job->getLotNumber() << std::endl;
			count++;
		}
	}
	else
	{
		std::cout << "There are currently no unassigned jobs. . ." << std::endl;
		return false;
	}
	return true;
}
void createNewJob(std::vector<std::unique_ptr<Jobs>>& jobsVec, std::vector<std::shared_ptr<Community>>& comVec)
{
	if (comVec.size() == 0)
	{
		system("cls");
		
		std::cout << "There are no communities created!" << std::endl;
		std::cout << "Create one now? (Y/N): ";
		char input = getInput();
		
		if (input == 'Y')
			createNewCommunity(comVec);
		else
		{
			std::cout << "Cannot create Job without a community. . . .Returning to menu" << std::endl;
			return;
			
		}
	}
	system("cls");
	displayCommunityList(comVec);
	std::cout << "\n0 - Create new Community" << std::endl;
	
	int comSelect{};
	bool valid{false};
	do{
		std::cout << "Which community is this job a part of? (Select number): ";
		std::cin >> comSelect;
		comSelect--;
		int comVecSize = comVec.size();
		if (comSelect == -1)
		{
			createNewCommunity(comVec);
			comSelect = comVec.size() - 1;
			valid = true;
		}
		
		else if(comSelect >= 0 && comSelect < comVecSize)
			valid = true;
	}while(!valid);
	
	int lotNumber{};
	system("cls");
	std::cout << "What is the lot number?" << std::endl;
	std::cout << comVec.at(comSelect)->getName() << " - Lot: ";
	std::cin >> lotNumber;
	bool duplicate{false};
	for (const auto &job : jobsVec) // Check to see if Lot number already exists for the Community the job is for
	{
		if (job->com.getName() == comVec.at(comSelect)->getName() &&
			job->getLotNumber() == lotNumber) 
			duplicate = true;
	}
	if (!duplicate) // If no duplicate lot number, create job and move to open Jobs vector
	{
		std::unique_ptr<Jobs> job = std::make_unique<Jobs>(*comVec.at(comSelect), lotNumber);
		jobsVec.push_back(std::move(job));
	}
	else
	{
		std::cout << "This job already exists!" << std::endl;
	}
}

void editCommunityList(std::vector<std::shared_ptr<Community>>& comVec)
{
	if (comVec.size() == 0)
	{
		std::cout << "No communities currently in list . . .Returning to menu" << std::endl;
		return;
	}
	bool valid{false};
	char input{};
	int inputNum{};
	do // loop until input is a valid selection
	{	
		system("cls");
		displayCommunityList(comVec);
		std::cout << "X - Go back" << std::endl;
		std::cout << "Select a community: ";
		input = getInput();
		inputNum = input - '0';
		inputNum--;
		int comVecSize = comVec.size();
		if (input == 'X' || (inputNum >= 0 && inputNum < comVecSize))
			valid = true;
	}while(!valid);
	
	if (input == 'X')
		return;
		
	system("cls");
	std:: cout << comVec.at(inputNum)->getName() << std::endl; // Display selected Community 
	
	
	
	do
	{	
		std::cout << "\n1 - Edit name" << std::endl;
		std::cout << "2 - Delete community" << std::endl;
		std::cout << "\nX - Go Back" << std::endl;

		input = getInput();
		if (input == 'X' || input == '1' || input == '2')
			valid = true;
	}while(!valid);
	
	switch (input)
	{
		case 'X': // Go back
			return;
		case '1': // Edit name
			editCommunityName(comVec.at(inputNum));
			break;
		case '2': // Delete community
			//deleteCommunity(comVec.at(inputNum));
			comVec.at(inputNum).reset();
			comVec.erase(comVec.begin()+inputNum);
			break;
	}
}

void editCommunityName(std::shared_ptr<Community>& com)
{
	std::string name{};
	system("cls");
	std::cout << com->getName() << std::endl;
	std::cout << "Enter a new name: ";
	std::cin.ignore();
	std::getline(std::cin, name);
	name.at(0) = toupper(name.at(0));
	
	com->setName(name);
}