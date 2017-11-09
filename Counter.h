// In a header

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
		std::cout << "Stats" << std::endl;
#define SHOW(d) std::cout << #d << ": " << d << std::endl
		SHOW(copies);
		SHOW(moves);
		SHOW(creations);
		SHOW(alives);
#undef SHOW
		std::cout << "-------------------------" << std::endl;
	}
};


// In an implementation file
#define INIT(d) template<class T> int OperationCounter<T>::d = 0;
INIT(copies);
INIT(moves);
INIT(creations);
INIT(alives);
#undef INIT
