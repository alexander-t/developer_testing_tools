package cofoja;

import com.google.java.contract.Requires;

/**
* This class demonstrates how Cofoja crashes when a precondition 
* is violated.
*/
public class Time {
    private int hour;
    private int minute;

    // This only serves to illustrate a Cofoja annotation
    @Requires({"hour >=0 && hour <= 23", "minute >=0 && minute <= 59"})
    public Time(int hour, int minute) {
        this.hour = hour;
        this.minute = minute;
    }
	
	public static void main(String ... args) {
		new Time(10, -1);
	}

}
