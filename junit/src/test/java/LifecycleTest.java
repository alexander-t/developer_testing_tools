import org.junit.*;

/**
 * Test initializers and cleanup
 */
public class LifecycleTest {

    @BeforeClass
    public static void setupOnce() {
        System.err.println("setupOnce: Executed once per test class");
    }

    @Before
    public void setup() {
        System.err.println("setup: Executed for every test");
    }

    @Test
    public void testMethod() {
        System.err.println("Running test method");
    }

    @After
    public void tearDown() {
        System.err.println("tearDown: Executed for every test");
    }

    @AfterClass
    public static void tearDownOnce() {
        System.err.println("tearDown: Executed once per test class");
    }
}
