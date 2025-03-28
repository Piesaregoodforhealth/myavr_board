#ifndef IEXECUTABLE_H
#define IEXECUTABLE_H

class IExecutable {
	public:
	virtual void doExec(int cycle_counter) = 0; // Pure virtual function
	virtual ~IExecutable() throw() = default; // Virtual destructor for proper cleanup
};

#endif // IEXECUTABLE_H
