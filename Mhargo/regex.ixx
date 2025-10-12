export module regex;
import std;

export class regex
{
public:
	struct symbolMatcher
	{
		char rangeBegin, rangeEnd;
		enum repetitionType { ONCE, ZERO_OR_ONCE, ZERO_OR_MORE, ONE_OR_MORE, EXACTLY_N, AT_LEAST_N, BETWEEN_N_AND_M, N_TIMES, NULL } repetition = NULL;
		unsigned int n = 0, m = 0;
		unsigned repetitionTimes = 0;
		bool wildcard = false, range = false;
	};

	regex(std::string rule);
	~regex();
	bool match(const char* str, const int unsigned& length);
	bool match(const std::string& str);

	void where(const char* str, const int unsigned& length, unsigned int& beginIndex, unsigned int& endIndex);
	void where(const std::string& str, unsigned int& beginIndex, unsigned int& endIndex);

	inline bool isInRange(char ch, auto& rule);

	void ruleAnalysis(const symbolMatcher& symbolMatchTable);

private:
	std::string regexRule;
	symbolMatcher* symbolMatchTab = new symbolMatcher[256];
};