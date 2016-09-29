import org.junit.Rule;
import org.junit.Test;
import org.junit.rules.ExpectedException;

import static org.hamcrest.core.Is.isA;


/**
 * Exception handling
 */
public class ExceptionsTest {

    @Rule
    public ExpectedException exception = ExpectedException.none();

    @Test(expected = IllegalArgumentException.class)
    public void usingAnnotation() {
        throw new IllegalArgumentException("Fail!");
    }

    @Test
    public void usingRule() {
        exception.expect(IllegalArgumentException.class);
        exception.expectMessage("Epic");
        exception.expectCause(isA(IllegalStateException.class));
        throw new IllegalArgumentException("Epic", new IllegalStateException("Fail"));
    }
}
