import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.Parameterized;
import static org.junit.runners.Parameterized.*;

import java.util.Arrays;
import java.util.Collection;

import static org.junit.Assert.assertEquals;
import static org.junit.runners.Parameterized.Parameters;

/**
 * Parameterized test using injection
 */
@RunWith(Parameterized.class)
public class ParameterizedInjectionTest {

    @Parameters
    public static Collection<Object[]> data() {
        return Arrays.asList(new Object[][] {
                {"Hello", "World", "Hello World"},
                {"You", "Me", "You Me"}
        });
    }

    @Parameter
    public String firstWord;

    @Parameter(value = 1)
    public String secondWord;

    @Parameter(value = 2)
    public String concatenated;

    @Test
    public void usingInjection() {
        assertEquals(concatenated, firstWord +  " " + secondWord);
    }
}
