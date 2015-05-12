
#include<iostream>

using namespace std;


//only requirement from the command : it should be executable
// interface with a single pure virtual function:

class Command
{
public:
	virtual void Execute() = 0;
};

//simple class with single method recieving command 
class Receiver
{
public:
	//the action to be executed

	void Action()
	{
		std::cout << "Command received" << std::endl;
		
	}
	
};
// invoker to invoke the command
class Invoker
{
	Command *m_command;

public:
	Invoker(Command *cmd = 0) : m_command(cmd)
	{
	}

	//SetCommand() function which lets to bind another command to the Invoker at run-time
	void SetCommad(Command *cmd)
	{
		m_command = cmd;
	}

	void Invoke()
	{
		// yoda notation 

		if (0 != m_command)
		{
			m_command->Execute();
		}
	}
};
class MyCommand : public Command
{
	Receiver *m_receiver;

public:
	MyCommand(Receiver *rcv = 0) : m_receiver(rcv)
	{
	}

	//SetReceiver() function makes it easy to bind another receiver to the command
	void SetReceiver(Receiver *rcv)
	{
		m_receiver = rcv;
	}
	
	virtual void Execute()
	{
		if (0 != m_receiver)
		{
			m_receiver->Action();
		}
	}
};

int main()
{
	Receiver r;
	MyCommand cmd(&r);
	Invoker caller(&cmd);
	caller.Invoke();
	cin.get();
	return 0;
}