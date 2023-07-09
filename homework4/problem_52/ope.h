#include "operation.h"

class ope_jia: public OperationNodeTwo{
	public:
	ope_jia(string name, Node *x1, Node *x2): OperationNodeTwo(name, x1, x2){}
	void UpdateValue()
	{
		value_ = input1->value() + input2->value();
	}
};

class ope_jian: public OperationNodeTwo{
	public:
	ope_jian(string name, Node *x1, Node *x2): OperationNodeTwo(name, x1, x2){}
	void UpdateValue()
	{
		value_ = input1->value() - input2->value();
	}
};