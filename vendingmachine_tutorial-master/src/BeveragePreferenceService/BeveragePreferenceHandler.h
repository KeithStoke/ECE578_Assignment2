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
  BeveragePreferenceeHandler();
  ~BeveragePreferenceHandler() override=default;
  
  Beverage::type getBeverage(const BeverageType::type btype) override;
};

// Constructor
BeveragePreferenceServiceHandler::BeveragePreferenceServiceHandler() {

}

// Remote Procedure "PlaceOrder"

Beverage::type getBeverage(const BeverageType::type btype) {
     // Your implementation goes here
     printf("GetBeveragePreference\n");

    // randomly select a weather
	if( btype == WeatherType::type::COLD)
	{
		return (0 == rand()%3)? Beverage::type::LEMONADE : Beverage::type::ICE_TEA :Beverage::type::SODA;
	}
	else
	{
		return (0 == rand()%3)? Beverage::type::CAPPUCCINO : Beverage::type::LATTE :Beverage::type::ESPRESSO;
	}
}

} // namespace vending_machine


#endif //VENDING_MACHINE_MICROSERVICES_WEATHERHANDLER_H
