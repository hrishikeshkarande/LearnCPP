#include <iostream>

//Declaring a class
class GPSCoord{
    private:
    //latitude,longitude and elevation:
    double lat, lng, elev;
    public:
    //set latitude and longitude:
    void set(double la, double lo);
    void setElevation(double val);
    double getLatitude();
    double getLongitude();
};

//Implementing the methods for the above declared class
void GPSCoord::set(double la, double lo)
{
    lat = la; 
    lng = lo;
}

void GPSCoord::setElevation(double val)
{
    elev = val;
}

double GPSCoord::getLatitude()
{
    return lat;
}

double GPSCoord::getLongitude()
{
    return lng;
}

int main() {
    GPSCoord here; //Created an object of GPSCoord class

    here.set(58.232,87.242); //We can modify the values of latitude and longitude using the set method

    here.setElevation(99.876); //We can also set the elevation using the setElevation method

    //We can retrieve using the below methods
    double retrievedlat = here.getLatitude();
    double retrievedlng = here.getLongitude();

    std::cout << "Latitude: " << retrievedlat << ", Longitude: " << retrievedlng << std::endl;
    //std::cout << "Elevation: " << here.elev << std::endl; // Accessing elevation directly, not recommended in practice //Actually this is declared private



    /********************/

    //Now we will do something using pointer to object

    GPSCoord * coordpointer = new GPSCoord();
    coordpointer -> set(0,0);
    coordpointer -> setElevation(0);
    
    std::cout << "Pointer to object - Latitude: " << coordpointer->getLatitude()
              << ", Longitude: " << coordpointer->getLongitude() << std::endl;

    // Clean up the dynamically allocated memory
    delete coordpointer;

    coordpointer = NULL; // Set pointer to NULL after deletion to avoid dangling pointer

    return 0;  

}

/* This code demonstrates the use of a class in C++ to represent GPS coordinates.
It includes methods to set and get latitude, longitude, and elevation. 
The main function creates an object of the class, sets its values, 
retrieves them, and also demonstrates the use of a pointer to an object. 
The code is written in C++20 standard.
*/