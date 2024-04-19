#include "Api.class.h"


/*
 * double getPrice(QString shortName){ */
        /*financialmodelingprep */
        /*$data =file_get_contents("https://financialmodelingprep.com/api/v3/quote-short/$shortName?apikey=$this->apikey");


        $array = json_decode($data);

        $obj = $array[0];

        $price = $obj->price;

        return $price;*/
        //return 32.22;
//}

int Api::getPrice(QString shortName){
    return 32;
}
