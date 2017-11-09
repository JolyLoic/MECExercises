template<class T>
struct OperationCounter
{
	static int copies;
	static int moves;
	static int creations;
	static int alives;

	OperationCounter()
	{
		++alives;
		++creations;
	}
	~OperationCounter()
	{
		--alives;
	}
	OperationCounter(OperationCounter const &)
	{
		++alives;
		++creations;
		++copies;
	}
	OperationCounter(OperationCounter &&) noexcept
	{
		++alives;
		++creations;
		++moves;
	}
	OperationCounter &operator=(OperationCounter const &) = delete;
	OperationCounter &operator=(OperationCounter &&) = delete;
	static void stats()
	{
		cout << "Stats" << endl;
#define SHOW(d) cout << #d << ": " << d << endl
		SHOW(copies);
		SHOW(moves);
		SHOW(creations);
		SHOW(alives);
#undef SHOW
		cout << "-------------------------" << endl;
	}
};
