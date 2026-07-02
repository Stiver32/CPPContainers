template <typename T>
class Node
{
public:
	Node* _next; //ptr to next node
	T _value;

	Node(T& value) : _next(nullptr), _value(value) {}
};