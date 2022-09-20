public class ElectricVehicle extends Vehicle {    
    
    public static double centsPerKwhOfElectricity = Double.NaN;
    private double whPerMile;
    private double kwhInBattery;

    public ElectricVehicle(int year, String make, String model, BodyStyle bodyStyle, double whPerMile, double kwhInBattery) {
        super(year, make, model, bodyStyle);
        this.whPerMile = whPerMile;
        this.kwhInBattery = kwhInBattery;
    }


    @Override
    public double range() {
        return kwhInBattery / (whPerMile / 1000);
    }

    @Override
    public double fuelConsumed(double miles) {
        double consumed = miles * (whPerMile / 1000);
        if (consumed > kwhInBattery) throw new ArithmeticException("Consumed more fuel possible in 1 charge.\n");
        return consumed;
    }

    @Override
    public double dollarsToTravel(double miles) {
        return fuelConsumed(miles) * (centsPerKwhOfElectricity / 100);
    }
}