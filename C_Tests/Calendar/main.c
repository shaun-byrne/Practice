#include "output.h"
#include "input.h"

enum Month {
	January,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December,
	Number_of_months
};

static enum Month MonthFromDay(unsigned day);
static unsigned WeekDayFromDay(unsigned day);
static unsigned DayFromYear(unsigned year);
static unsigned YearFromDay(unsigned day);

static const unsigned DAYS_IN_YEAR = 365;
static const unsigned FIRST_YEAR_IN_RECORD = 1512;
static const char *DAY[] = { "Monday", "Tuesday", "Wednesday", "Thursday",
		"Friday", "Saturday", "Sunday" };
static const char *MONTH[] =
		{ "January", "February", "March", "April", "May", "June", "July",
				"August", "September", "October", "November", "December", };

int main(int argc, char **argv) {
	const unsigned day = DayFromYear(In_ReadCalendarYear(argv));

	for (unsigned i = day - DAYS_IN_YEAR; i < day + DAYS_IN_YEAR; i++)
		Out_WriteCalendarLine(i % DAYS_IN_YEAR + 1, DAY[WeekDayFromDay(i)],
				MONTH[MonthFromDay(i)], YearFromDay(i));

	return 0;
}

static unsigned WeekDayFromDay(unsigned day) {
	return day % 7;
}

static enum Month MonthFromDay(unsigned day) {
	if (day <= 30)
		return January;
	else if ((day > 30) && (day <= 59))
		return February;
	else if ((day > 59) && (day <= 90))
		return March;
	else if ((day > 90) && (day <= 120))
		return April;
	else if ((day > 120) && (day <= 151))
		return May;
	else if ((day > 151) && (day <= 181))
		return June;
	else if ((day > 181) && (day <= 212))
		return July;
	else if ((day > 212) && (day <= 242))
		return August;
	else if ((day > 242) && (day <= 273))
		return September;
	else if ((day > 273) && (day <= 303))
		return October;
	else if ((day > 303) && (day <= 334))
		return November;
	else if ((day > 334) && (day <= 364))
		return December;
	else
		return January; //TODO: Error handling
}

static unsigned DayFromYear(unsigned year) {
	unsigned day = year - FIRST_YEAR_IN_RECORD;

	return day * DAYS_IN_YEAR;
}

static unsigned YearFromDay(unsigned day) {
	unsigned year = FIRST_YEAR_IN_RECORD;

	for (unsigned i = day; i > 0; i--) {
		if (i % 364 == 0)
			year++;
	}

	return year;
}
