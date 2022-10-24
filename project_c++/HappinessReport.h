#ifndef HAPPINESSREPORT_H
#define HAPPINESSREPORT_H
#include <string>
struct HappinessReport
{
    //,Happiness Rank,Country,Region,Happiness Score,Economy (GDP per
    //Capita),Family (Social Support),Health (Life Expectancy),Freedom,Trust
    //(Government Corruption),Generosity,Year
    int happinessRank;
    std::string country;
    std::string region;
    double happinessScore;
    double socialSupport;
    double lifeexpectancy;
    double freedom;
    double gdp;
    double trust;
    double generosity;
    int year;
};
#endif  // HAPPINESSREPORT_H
