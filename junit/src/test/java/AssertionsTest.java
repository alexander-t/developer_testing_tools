import org.junit.Test;

import java.util.Arrays;

import static org.junit.Assert.*;

/**
 * Assertions
 */
public class AssertionsTest {

    @Test
    public void basicEquality() {
        final int expected = 42;
        assertEquals(expected, 42);
        assertNotEquals(expected, 43);
    }

    @Test
    public void collectionEquality() {
        // Collections are equal if their members implement equals (which wrapper types do)
        assertEquals(Arrays.asList(1, 2, 3), Arrays.asList(10 - 9, 10 / 5, 10 % 7));
    }

    @Test
    public void arrayEquality() {
        final int[] expected = new int[]{1, 2, 3};
        assertArrayEquals(expected, new int[] {2 - 1, 6 % 4, 3});
    }

    @Test
    public void decimalEquality() {
        final double expectedDecimal = 42.0;
        final double precision = 0.1;

        // Equal because of precision
        assertEquals(expectedDecimal, 42.01, precision);
    }

    @Test
    public void truth() {
        assertTrue(true);
        assertFalse(false);
    }

    @Test
    public void nulls() {
        assertNull(null);
        assertNotNull("null");
    }

    @Test
    public void unconditionalFailure() {
        fail("This test will fail");
    }
}
