import java.util.Stack;
import java.util.Collections;
import java.util.EmptyStackException;

public class Deck {

    private Stack<Card> deck; 
    
    public Deck() {
        deck = new Stack<>();
        Rank rank;
        Card card;

        for(Suit suit : Suit.values()) {
            for(int i = Rank.MIN; i < Rank.MAX+1; i++) {
                deck.push(new Card(new Rank(i), suit));
            }
        }
    }

    public class DeckEmpty
        extends IndexOutOfBoundsException {
            public DeckEmpty(String errorMessage) {
                super(errorMessage);
            }
        }
        
        public void shuffle() {
            Collections.shuffle(deck);
        }
        
        public boolean isEmpty() {
            return deck.empty();
        }
        
        public Card deal() {
            if (deck.empty()) throw new DeckEmpty("Deck is empty.");

            return deck.pop();
        }
    }