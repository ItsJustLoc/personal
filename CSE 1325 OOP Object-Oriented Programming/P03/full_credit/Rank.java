public class Rank {
    
    private int rank;

    public Rank(int rank) {
        this.rank = rank;
        //rank = (int) ((Math.random() * (MAX - MIN)) + MIN);
        if(MAX < rank || rank < MIN) throw new IllegalArgumentException("Invalid Rank " + rank);
    }

    public final static int MIN = 0;
    public final static int MAX = 9;

    @Override
    public String toString() {
        return "" + rank;
    }
}