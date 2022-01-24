package HotelDetails;

import java.io.*;
import java.util.*;


public class Menu {

    Scanner input = new Scanner(System.in);

    Room[] myHotel = new Room[11];

    static String choice;
    static String roomName;
    static int roomNum = 1;
    static String answer;


    public void menu() {
        System.out.println("======================================================");
        System.out.println("*            Hotel Management System                 *");
        System.out.println("======================================================");
        System.out.println("* V. View all the rooms                              *");
        System.out.println("* A. Add customer to room                            *");
        System.out.println("* E. Display Empty rooms                             *");
        System.out.println("* D. Delete customer from room                       *");
        System.out.println("* F. Find room from customer name                    *");
        System.out.println("* S. Store program array data into a text file       *");
        System.out.println("* L. Load program data back from the file            *");
        System.out.println("* O. View rooms Ordered alphabetically by name       *");
        System.out.println("* Q. Quit Program                                    *");
        System.out.println("======================================================");
        System.out.println("");

        System.out.println("Choose one of the options from above. (E.g: Type 'V' to view all the rooms)");

        do {
            System.out.println();
            System.out.print("Choice : ");
            choice = input.next();
            String selection = choice.toLowerCase(); //This will convert the input value to lowercase. this will help avoid case sensitive issues.

            switch (selection) {

                case "v":
                    viewRooms();
                    break;
                case "a":

                    addCustomer();
                    break;

                case "e":
                    displayEmptyRooms();
                    break;

                case "d":
                    deleteCustomer();
                    break;

                case "f":
                    findRoom();
                    break;

                case "s":
                    storeData();
                    break;

                case "l":
                    retrieveData();
                    break;

                case "o":
                    alphabeticalOrder();
                    break;

                case "q":
                    System.out.println("Thanks");
                    System.exit(0);
                    break;

                default:
                    System.out.println("Invalid input! Please Enter one of these letters: V,A,E,D,F,S,L,O,Q");
            }
        }
        while (!(choice.equalsIgnoreCase("v") || choice.equalsIgnoreCase("a") || choice.equalsIgnoreCase("e") || choice.equalsIgnoreCase("d") ||
                choice.equalsIgnoreCase("f") || choice.equalsIgnoreCase("s") || choice.equalsIgnoreCase("l") || choice.equalsIgnoreCase("o") ||
                choice.equals("3") || choice.equalsIgnoreCase("q"))); //condition to only let valid range of inputs through.
    }



    public void initialize() {
        for (int x = 1; x <= 10; x++) {
            myHotel[x] = new Room(); //Creating 10 Room Objects
        }
    }



    public void viewRooms() {
        for (int x = 1; x < 11; x++) {
            //This will display the room number and the current owner's name
            if (!myHotel[x].isEmpty()) {
                System.out.println("Room No. " + x + " occupied by " + myHotel[x].getName());
                //This will display the rooms which are currently Empty
            } else {
                System.out.println("Room No. " + x + " is empty");
            }

        }
        menu();
    }



    public void addCustomer() {

        boolean invalidRoomNumber=true; //Declaration of a boolean variable.

        do {
            try {
                System.out.println("Enter room number (1-10)");
                roomNum = input.nextInt();
                
                //checks whether the room is already occupied or not
                if (!myHotel[roomNum].isEmpty()) {
                    invalidRoomNumber = true;
                    System.out.println("This room is occupied by: Mr. " + myHotel[roomNum].getName());
                    System.out.println("");
                    //checks whether the input is within the proper range
                } 
                else {	//the room number is valid and empty
                    invalidRoomNumber = false;
                    //Error message to be displayed
                } 
                
                //if the input is out of the range of the hotel array this will catch it
            } catch (IndexOutOfBoundsException e) {	//only array index in the range can be accessed
                invalidRoomNumber = true;
                System.out.println("Invalid input! Please Enter a value between 1-10!!");
                System.out.println("");
                //to deal with exceptions regarding null values
            } 
            
            catch (NullPointerException e) {		//Null pointer 
                invalidRoomNumber = true;
                //System.out.println("Invalid input! Please Enter a value between 1-10");
                System.out.println("Invalid input! Please enter a nonzero number!!");
                
            } 
            
            catch (InputMismatchException e) {	//only numbers are valid
                invalidRoomNumber = true;
               // System.out.println("Invalid input! Please Enter a value between 1-10");
                System.out.println("Invalid input! Please enter a number!!");
                input.next();
            }
        } while (invalidRoomNumber);
        System.out.println("Enter the name of the customer :");
        //Getting the customer's name
        roomName = input.next();
        String cap = roomName.substring(0, 1).toUpperCase() + roomName.substring(1).toLowerCase(); 	//Captilise the first letter for easy Sorting
        roomName = cap;
        //Setting the customer name
        myHotel[roomNum].setName(roomName);
        myHotel[roomNum].setEmpty(false);

        //this will let you choose whether to add more data or not
       
            do {
                System.out.println("Do you want to continue adding records? (Y/N)");
                answer = input.next();
                String selection = answer.toLowerCase();
                
                if (!selection.equalsIgnoreCase("y") && !selection.equalsIgnoreCase("n") )  {
		 	System.out.println("Invalid input! Please enter y or n!");
		 	continue;
		 	}
		 	
		 	
                switch (selection) {
                    case "y":
                        addCustomer();		//recursive call

                    case "n":
                        System.out.println("");
                        menu();
                        
                    
                   
                }

            } while (!(answer.equalsIgnoreCase("y") || answer.equalsIgnoreCase("n")));

        }
    


    public void displayEmptyRooms() {
        //this method will display all the empty rooms
        for (int x = 1; x <= 10; x++) {
            if (myHotel[x].isEmpty()) {
                System.out.println("room " + x + " is empty");
            }
        }
        System.out.println("");
        menu();
    }


    private void deleteCustomer() {
    	boolean allEmpty=true;
    	for(int i=1; i<=10; i++){
    		if(!myHotel[i].isEmpty()){
    			allEmpty=false;
    		}
    	}
    	if(allEmpty){
    		System.out.println("All the rooms are already empty");
    		menu();
    	}

        boolean invalidInput;

        do {
            invalidInput = false;
            try {
                System.out.println("please enter the Room's number which you want to vacate");
                roomNum = input.nextInt();

                //if the hotel room is not empty then this will delete the customer from that room
                if (!(myHotel[roomNum].isEmpty())) {
                    invalidInput = false;
                    myHotel[roomNum].setEmpty(true);

                    //if the room is already empty then this message will be displayed
                } else {
                    invalidInput = true;
                    System.out.println("Room " + roomNum + " is already Empty");
                    System.out.println("");
                }

                //if the input is not an integer value then this will catch it
            } 
            
            catch (InputMismatchException e) {
                invalidInput = true;
                System.out.println("Invalid input! Please enter a number!!");
                System.out.println("");
                input.next();
                //if the input is out of the range of the hotel array this will catch it
            }
             
            catch (IndexOutOfBoundsException e) {
                invalidInput = true;
                System.out.println("Invalid room number. Please enter a value between 1-10!!");
                input.next();
            }
            
            catch (NullPointerException e) {		//Null pointer 
                invalidInput = true;
                //System.out.println("Invalid input! Please Enter a value between 1-10");
                System.out.println("Invalid input! Please enter a nonzero number!!");
            } 

        } while (invalidInput);//This will print the room's number which has been successfully vacated
        System.out.println("Room " + roomNum + " has successfully been vacated");
        System.out.println("");
        menu();
    }

    public void doFind(String find){
           boolean found = false;
    	   for (int n = 1; n <= 10; n++) {
            //used equalsIgnoreCase to avoid case sensitive issues while searching for a customer
            //this method will find the room's number which is currently being occupied by the mentioned customer
            if (myHotel[n].getName().equalsIgnoreCase(find)) {
                found = true;
                System.out.println("Mr. " + myHotel[n].getName() + " is staying in room No. " + n);
                System.out.println("");

            }
        }
        //this will let ou know if the customer is not there in the database
        if (found == false) {
            System.out.println(find + " doesn't exist on our database");
            System.out.println("");
            
        }
    
    }

    public void findRoom() {
        System.out.println("Please enter the name of the customer");
        
        String find = input.next();

	doFind(find);
     
        menu();
    }


    public void storeData() {
        try {
            //saving Data and overwriting
	    int state;
            String[] storage = new String[11];

            for (int y = 1; y <= 10; y++) {
            	 if(myHotel[y].isEmpty())
            	 	state = 1;
            	 else
            	 	state = 0;
            	 
            	 
                storage[y] = myHotel[y].getName()+" "+state;
            }

            BufferedWriter bw = new BufferedWriter(new FileWriter("HotelDetails/data.txt", false)); //used false to overwrite the file instead of appending
            for (int x = 1; x < storage.length; x++) {
                String file;
                file = storage[x];
                // writes Empty room if it find "e" on the array
                if (file.charAt(file.length() - 1) == '1')
                
                {
                    bw.write("Empty Room " + x);

                    // writes the name of the customer from the array
                } else {
                    bw.write(file);
                }
                bw.newLine(); //Line Seperator
                bw.flush(); //Flushes the stream.

            }

            //will catch this exception if the Text file is not found
        } catch (IOException e) {
            System.err.println("File not found!");
        }

        //message to show the user that the array data has been saved to a Text file successfully
        System.out.println("Data successfully saved!");
        System.out.println("");
        menu();
    }

    public void retrieveData() {

        try {
            //reading Data from the Text File
            BufferedReader reader = new BufferedReader(new FileReader("HotelDetails/data.txt"));

            for (int x = 1; x <= 10; x++) {
                String read = reader.readLine(); //Reads String value stored in the Text File
                if (read.equals("Empty Room " + x)) {
                    myHotel[x].setEmpty(true);
                }
                //Stored the data in the Hotel Array
                else {
                	myHotel[x].setEmpty(false);
                	myHotel[x].setName(read.substring(0,read.length()-2));
            	}
            
            }

            //will catch this exception if the Text file is not found
        } catch (IOException e) {
            System.err.println("File not found!");
        }
        //Displays this message if the file is found and successfully loaded the data back from it
        System.out.println("File successfully loaded");
        System.out.println("");
        menu();
    }


    public void alphabeticalOrder() {

		boolean allEmpty=true;
    	for(int i=1; i<=10; i++){
    		if(!myHotel[i].isEmpty()){
    			allEmpty=false;
    		}
    	}
    	if(allEmpty){
    		System.out.println("All the rooms are empty!!");
    		menu();
    	}

        int index = 0;        
        ArrayList<String> names = new ArrayList<String>();
        for (int y = 1; y < 11; y++) {
            if(!myHotel[y].isEmpty())
            	names.add(myHotel[y].getName());
        }
        
        //sorting the Arraylist
        Collections.sort(names);
        for(String i : names) {
        	doFind(i);
        }
        
        menu();

    }

}

