using namespace std;

class IBaseSortable
{
	public:
		virtual bool operator<(IBaseSortable & obj) = 0;
		virtual bool operator>(IBaseSortable & obj) = 0;
		virtual bool operator==(IBaseSortable & obj) = 0;
};

