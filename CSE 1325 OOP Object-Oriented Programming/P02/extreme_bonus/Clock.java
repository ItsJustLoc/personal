public class Clock {
    private int hours;
    private int minutes;
    private int seconds;

    public Clock(int hours, int minutes, int seconds) {
        this.hours = hours;
        this.minutes = minutes;
        this.seconds = seconds;
    }

    @Override
    public String toString() {
        rationalize();
        String hour = twoDigits(hours);
        String minute = twoDigits(minutes);
        String second = twoDigits(seconds);
        return hour + ":" + minute + ":" + second;
    }

    private String twoDigits(int i) {
        String formatted = String.format("%02d", i);
        return formatted;
    }

    private void rationalize() {
        if(seconds < 0 || seconds > 59) {
            while(seconds < 0) {
                seconds += 60;
                minutes--;
            }
            while(seconds > 59) {
                seconds -= 60;
                minutes++;
            }
        }

        if(minutes < 0 || minutes > 59) {
            while(minutes < 0) {
                minutes += 60;
                hours--;
            }
            while(minutes > 59) {
                minutes -= 60;
                hours++;
            }
        }

        if(hours < 0 || hours > 23) {
            while(hours < 0) {
                hours += 24;
            }
            while(hours > 23) {
                hours -= 24;
            }
        }
    }

    public Clock add(int seconds) {
        Clock temp = new Clock(this.hours, this.minutes, this.seconds+seconds);
        return temp;
    }

    public Clock add(Clock clock) {
        Clock clone = new Clock(clock.hours, clock.minutes, clock.seconds);
        clone.seconds   += this.seconds;
        clone.minutes   += this.minutes;
        clone.hours     += this.hours;
        rationalize();

        return clone;
    }
}