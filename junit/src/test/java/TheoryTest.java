import org.junit.experimental.theories.DataPoints;
import org.junit.experimental.theories.Theories;
import org.junit.experimental.theories.Theory;
import org.junit.runner.RunWith;

import static org.junit.Assert.assertTrue;
import static org.junit.Assume.assumeTrue;

/**
 * Theory test
 */
@RunWith(Theories.class)
public class TheoryTest {

    // Data points can be supplied using methods
    @DataPoints
    public static int[] count() {
        return new int[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    }

    @DataPoints
    public static String[] animal = new String[]{"cat", "dog", "bird"};

    @Theory
    public void animalsArePluralized(int count, String animal) {
        assumeTrue(count > 1); // Discard 1s to get nice plurals
        assertTrue(pluralize(count, animal).matches("^\\d{1,2} \\w+s$"));
    }

    public static String pluralize(int count, String s) {
        return String.format("%d %ss", count, s);
    }
}
