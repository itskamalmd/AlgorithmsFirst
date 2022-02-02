import java.util.Arrays;
import java.util.Scanner;

class Airport {
    String name;
    String code;

    Airport(String name,String code){
        this.name = name;
        this.code = code;
    }
    public String toString(){
        return "Name : " + this.name + " ; " + "code : " + this.code;
    }
}
public class linearSearchBinarySearchSorting {

    static Airport findAirport(String SearchText,Airport[] airports){
        for (int i = 0; i < airports.length; i+=1){
            if (airports[i].name.equals(SearchText) || airports[i].code.equals(SearchText)){
                return airports[i];
            }
        }
        return null; 
    }
    static Airport[] sortAirports(Airport[] airports){
        // Airport[] temp = new Airport[airports.length];
        for (int i = 0; i < airports.length; i+=1){
            for (int j = 0; j < airports.length; j+=1){
               if (airports[i].name.charAt(0) < airports[j].name.charAt(0)){
                   Airport temp = airports[j];
                   airports[j] = airports[i];
                   airports[i] = temp;
               }
            }
        }
        return airports; 
    }
    static Airport findAirportBinary(Airport[] airports,String SearchText){
        Airport[] sortedAirports = sortAirports(airports.clone());
        int halfway = sortedAirports.length / 2;
        if (SearchText.charAt(0) == sortedAirports[halfway].name.charAt(0)){
            return sortedAirports[halfway];
        }
        else if (SearchText.charAt(0) < sortedAirports[halfway].name.charAt(0)  ){
            Airport[] slicedAirports =  Arrays.copyOfRange(sortedAirports,0,halfway);
                return findAirportBinary(slicedAirports,SearchText); 
        }
        else if (SearchText.charAt(0) > sortedAirports[halfway].name.charAt(0)  ){
            Airport[] slicedAirports = Arrays.copyOfRange(sortedAirports,halfway,airports.length);
                return findAirportBinary(slicedAirports,SearchText);
            }
        return null;
        }
    public static void main(String [] args){
        Airport[] airports = {new Airport("beijing","301"),new Airport("america","302"),new Airport("canada","303"),new Airport("japan","304"),new Airport("india","305")};
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the searh text: ");
        String SearchText = in.nextLine();
        /* Airport foundAirport = findAirport(SearchText, airports); 
        System.out.println(foundAirport); */
        System.out.println(findAirportBinary(airports,SearchText));
        
    }
}
