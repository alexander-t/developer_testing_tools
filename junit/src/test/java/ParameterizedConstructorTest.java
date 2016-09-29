import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.Parameterized;

import java.util.Arrays;
import java.util.Collection;

import static org.junit.Assert.assertEquals;
import static org.junit.runners.Parameterized.*;

/**
 * Parameterized test using constructor
 */
@RunWith(Parameterized.class)
public class ParameterizedConstructorTest {

    private String firstWord;
    private String secondWord;
    private String concatenated;

    @Parameters(name = "Case {index}: '{0}' concatenated with '{1}'")
    public static Collection<Object[]> data() {
        return Arrays.asList(new Object[][] {
                {"Hello", "World", "Hello World"},
                {"You", "Me", "You Me"}
        });
    }

    public ParameterizedConstructorTest(String firstWord, String secondWord, String concatenated) {
        this.firstWord = firstWord;
        this.secondWord = secondWord;
        this.concatenated = concatenated;
    }

    @Test
    public void usingConstructor() {
        assertEquals(concatenated, firstWord +  " " + secondWord);
    }
}
