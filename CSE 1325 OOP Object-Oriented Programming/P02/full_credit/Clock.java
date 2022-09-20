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
        String hour = twoDigits(hours);
        String minute = twoDigits(minutes);
        String second = twoDigits(seconds);
        return hour + ":" + minute + ":" + second;
    }
    private String twoDigits(int i) {
        String formatted = String.format("%02d", i);
        return formatted;
    }
}