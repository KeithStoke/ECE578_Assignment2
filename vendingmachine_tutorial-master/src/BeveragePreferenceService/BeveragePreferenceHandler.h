#ifndef VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H
#define VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H

#include <iostream>
#include <string>
#include <regex>
#include <future>

#include "../../gen-cpp/BeveragePreferenceService.h"

#include "../ClientPool.h"
#include "../ThriftClient.h"
#include "../logger.h"

namespace vending_machine{

class BeveragePreferenceServiceHandler : public BeveragePreferenceServiceIf {
 public:
   BeveragePreferenceServiceHandler();
  ~BeveragePreferenceServiceHandler() override=default;
  
  Beverage::type getBeverage(const BeverageType::type btype) override;
};

// Constructor
BeveragePreferenceServiceHandler::BeveragePreferenceServiceHandler() {

}

// Remote Procedure "PlaceOrder"

Beverage::type BeveragePreferenceServiceHandler::getBeverage(const BeverageType::type btype) {
     // Your implementation goes here
     printf("GetBeveragePreference\n");
	
	
	int test = rand()%3;
    // randomly select a weather
	if( btype == WeatherType::type::WARM)
	{
		if(test == 0)
			return (Beverage::type::LEMONADE);
		else if(test ==1)
			return (Beverage::type::ICE_TEA);
		else if(test ==2)
			return(Beverage::type::SODA);
	}	
	else
	{
		if(test == 0)
			return (Beverage::type::CAPPUCCINO);
		else if(test ==1)
			return (Beverage::type::LATTE);
		else if(test ==2)
			return(Beverage::type::ESPRESSO);
	}
}

} // namespace vending_machine


#endif //VENDING_MACHINE_MICROSERVICES_WEATHERHANDLER_H
