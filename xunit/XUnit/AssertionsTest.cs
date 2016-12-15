using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Xunit;

namespace XUnitTests
{
    public class AssertionsTest
    {
        [Fact]
        public void BasicEquality()
        {
            const int expected = 42;
            Assert.Equal(expected, 42);
            Assert.NotEqual(expected, 43);
        }

        [Fact]
        public void Ranges() {
            Assert.InRange(42, 1, 42);
            Assert.NotInRange(42, 1, 41);
        }

        [Fact]
        public void Truth()
        {
            Assert.True(true);
            Assert.False(false);
        }

        [Fact]
        public void Nulls()
        {
            Assert.Null(null);
            Assert.NotNull("null");
        }
    }
}
