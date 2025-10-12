module;

module regex;
import std;

regex::regex(std::string rule) : regexRule(rule)
{
	ruleAnalysis(*symbolMatchTab);
}
regex::~regex()
{
	delete[] symbolMatchTab;
}

bool regex::isInRange(char ch, auto& rule)
{
	if (rule.range)
		return (ch >= rule.rangeBegin && ch <= rule.rangeEnd);
	else
		return (ch == rule.rangeBegin);
}
void regex::ruleAnalysis(const symbolMatcher& symbolMatchTable)
{
	auto sm = &symbolMatchTab[0];
	unsigned int flag = 0;
	bool forFlag = false;
	for (auto ch : this->regexRule)
	{
		char* p = &ch;
		if (ch == '.' && flag == 0)
		{
			sm->wildcard = true;
			sm++;
			continue;
		}
		else if (ch == '[')
		{
			flag++;
			sm++;
			continue;
		}
		else if (ch == ']')
		{
			flag--;
			sm++;
			continue;
		}

		if (flag)
		{

			if (*p + 1 == '-')
			{
				sm->range = true;
				sm->rangeBegin = *p;
				sm->rangeEnd = *(p + 2);
				sm++;
				continue;
			}
			else
			{
				sm->range = false;
				sm->rangeBegin = ch;
				sm++;
				continue;
			}
		}

		if (ch == '?')
		{
			sm->repetition = symbolMatcher::ZERO_OR_ONCE;
		}
		else if (ch == '*')
		{
			sm->repetition = symbolMatcher::ZERO_OR_MORE;
		}
		else if (ch == '+')
		{
			sm->repetition = symbolMatcher::ONE_OR_MORE;
		}
		else if (ch == '{')
		{
			forFlag = true;
		}
		else if (ch == '}')
		{
			forFlag = false;
		}
		else if (forFlag && ch == ',')
		{
			sm->repetition = symbolMatcher::BETWEEN_N_AND_M;
		}
		else if (forFlag && sm->repetition != symbolMatcher::BETWEEN_N_AND_M)
		{
			sm->n = sm->n * 10 + (ch - '0');
		}
		else if (forFlag && sm->repetition == symbolMatcher::BETWEEN_N_AND_M)
		{
			sm->m = sm->m * 10 + (ch - '0');
		}
		else if (forFlag && *(p + 1) == '}')
		{
			sm->repetition = symbolMatcher::EXACTLY_N;
		}
		else
		{
			sm->range = false;
			sm->rangeBegin = ch;
			sm++;
		}
		sm++;
	}
}

bool regex::match(const char* str, const int unsigned& length)
{
	return false;
}
bool regex::match(const std::string& str)
{
	return false;
}

void regex::where(const char* str, const int unsigned& length, unsigned int& beginIndex, unsigned int& endIndex)
{

}
void regex::where(const std::string& str, unsigned int& beginIndex, unsigned int& endIndex)
{

}