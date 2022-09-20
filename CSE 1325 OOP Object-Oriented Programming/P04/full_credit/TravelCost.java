import java.util.Scanner;
import java.util.ArrayList;

public class TravelCost {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        ArrayList<Vehicle> vehicles = new ArrayList<>() {
            {
                add(new ElectricVehicle(2022, "Telsa",    "Model S Plaid",   BodyStyle.Sedan,     297, 100  ));
                add(new ElectricVehicle(2022, "Telsa",    "Model 3 LR",      BodyStyle.Sedan,     242,  82  ));
                add(new ElectricVehicle(2022, "GM",       "Bolt",            BodyStyle.Hatchback, 286,  66  ));
                add(new ElectricVehicle(2022, "Nissan",   "LEAF",            BodyStyle.Hatchback, 269,  60  ));
                add(new ElectricVehicle(2022, "Ford",     "Mustang Mach-E",  BodyStyle.SUV,       347,  88  ));
                add(new ElectricVehicle(2022, "Ford",     "F-150 Lightning", BodyStyle.Truck,     511, 131  ));
                add(new GasVehicle(     2022, "Ford",     "F-150",           BodyStyle.Truck,      25,  23  ));
                add(new GasVehicle(     2022, "Toyota",   "Prius Hybrid",    BodyStyle.Hatchback,  55,  11.4));
                add(new GasVehicle(     2022, "Toyota",   "RAV4",            BodyStyle.Crossover,  31,  14.5));
                add(new GasVehicle(     2022, "Nissan",   "Rogue",           BodyStyle.Hatchback,  33,  14.5));
                add(new GasVehicle(     2022, "Chrysler", "Pacifica",        BodyStyle.Minivan,    24,  19  ));
                add(new GasVehicle(     2022, "Chrysler", "Pacifica Hybrid", BodyStyle.Minivan,    30,  16.5));
            }
        };
        
        System.out.print("What is the price per gallon of gas (dollars)? ");
        GasVehicle.dollarsPerGallonOfGas = in.nextDouble();
        System.out.print("What is the price per kWh of electricity (cents)? ");
        ElectricVehicle.centsPerKwhOfElectricity = in.nextDouble();
        System.out.print("How many miles is your trip? ");
        double miles = in.nextDouble();

        for (Vehicle vehicle : vehicles) {
            System.out.printf("$%6.2f (range %.0f) %s\n", vehicle.dollarsToTravel(miles), vehicle.range(), vehicle);
        }
    }
}
