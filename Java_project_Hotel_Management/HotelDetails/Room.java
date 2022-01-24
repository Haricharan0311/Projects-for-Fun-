package HotelDetails;
public class Room {

    private String mainName;
    private boolean empty;   //to check if the room is occupied
    
    //Declaration of the constructor
    public Room() {
        mainName = " ";
        empty=true; 
    }

    //Sets the Name of the room
    public void setName(String aName) {
        mainName = aName;
    }

    //Gets the Name of the occupant
    public String getName() {
        return mainName;
    }
    
     //Sets status of the room
    public void setEmpty(boolean status) {
        empty = status;
    }
  
    //Returns true if empty
    public boolean isEmpty() {
        return empty;
    }

}
