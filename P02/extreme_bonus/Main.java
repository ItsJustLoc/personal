import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        int hours, minutes, seconds;
        Scanner in = new Scanner(System.in);
        
        System.out.print("Hours? ");
        hours = in.nextInt();
        System.out.print("Minutes? ");
        minutes = in.nextInt();
        System.out.print("seconds? ");
        seconds = in.nextInt();
        
        Clock time = new Clock(hours, minutes, seconds);
        System.out.println("The time is " + time);

        int i, toAdd;
        Clock time2 = null;
        System.out.print("Seconds to tic? ");
        toAdd = in.nextInt();
        
        for(i = 1; i < toAdd+1; i++) {
            time2 = time.add(i);
            System.out.println(time2);
        }

        while(toAdd != 0) {
            System.out.print("Seconds to add (0 to continue)? ");
            toAdd = in.nextInt();
            time2 = time2.add(toAdd);
            System.out.println(time2);
        }

        System.out.print("Add to that...\n");
        System.out.print("Hours? ");
        hours = in.nextInt();
        System.out.print("Minutes? ");
        minutes = in.nextInt();
        System.out.print("seconds? ");
        seconds = in.nextInt();

        time = new Clock(hours, minutes, seconds);

        Clock time3 = time2.add(time);
        System.out.println(time2 + " + " + time + " = " + time3);
    }
}