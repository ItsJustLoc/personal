public abstract class Vehicle {
    
    private int year;
    private String make;
    private String model;
    private BodyStyle bodyStyle;
    
    public Vehicle(int year, String make, String model, BodyStyle bodyStyle) {
        this.year = year;
        this.make = make;
        this.model = model;
        this.bodyStyle = bodyStyle;
    }
    
    public abstract double range();
    public abstract double fuelConsumed(double miles);
    public abstract double dollarsToTravel(double miles);
    
    @Override
    public String toString() {
        return String.format("%d %s %s %s", year, make, model, bodyStyle);
    }

}