public class GasVehicle extends Vehicle {
    
    public static double dollarsPerGallonOfGas = Double.NaN;
    private double milesPerGallon;
    private double gallonsInTank;

    public GasVehicle(int year, String make, String model, BodyStyle bodyStyle, double milesPerGallon, double gallonsInTank) {
        super(year, make, model, bodyStyle);
        this.milesPerGallon = milesPerGallon;
        this.gallonsInTank = gallonsInTank;
    }


    @Override
    public double range() {
        
        return gallonsInTank * milesPerGallon;
    }

    @Override
    public double fuelConsumed(double miles) {
        double consumed = miles / milesPerGallon;

        if (consumed > gallonsInTank) throw new ArithmeticException("Consumed more fuel possible in 1 tank.\n");

        return consumed;
    }

    @Override
    public double dollarsToTravel(double miles) {
        return fuelConsumed(miles) * dollarsPerGallonOfGas;
    }
}