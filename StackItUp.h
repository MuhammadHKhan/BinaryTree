template <class Type>
class myStack
{
public:
	myStack();
	myStack(const myStack<Type>&);
	const myStack<Type>& operator=(const myStack<Type>&);
	~myStack();

	void push(const Type&);
	void pop();
	Type top() const;
	bool isEmpty() const;

private:
	struct node
	{
		Type item;
		node* next;
	};

	node* topOfmyStack;
};


template <class Type>
myStack<Type>::myStack()
{
	topOfmyStack = NULL;
}

template <class Type>
myStack<Type>::myStack(const myStack<Type>& copy)
{
	*this = copy;
}

template<class Type>
const myStack<Type>& myStack<Type>::operator=(const myStack<Type>& rhs)
{
	if (*this != rhs)
	{
		*this = rhs;
	}

	return *this;
}

template<class Type>
myStack<Type>::~myStack()
{
	node* temp = topOfmyStack;
	while (topOfmyStack != NULL)
	{
		temp = temp->next;
		delete topOfmyStack;
		topOfmyStack = temp;
	}
}

template <class Type>
void myStack<Type>::push(const Type& insert)
{//aka headInsert
	node* temp = new node;
	temp->item = insert;
	temp->next = topOfmyStack;
	topOfmyStack = temp;
}

template <class Type>
void myStack<Type>::pop()
{//aka headRemove
	if (topOfmyStack == NULL)
	{
		return;
	}

	node* temp = topOfmyStack;
	topOfmyStack = topOfmyStack->next;
	delete temp;
	return;
}

template <class Type>
Type myStack<Type>::top() const
{
	return topOfmyStack->item;
}

template <class Type>
bool myStack<Type>::isEmpty() const
{
	if (topOfmyStack != NULL)
	{
		return false;
	}
	else
		return true;
}