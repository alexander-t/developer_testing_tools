using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Xunit;
using Xunit.Extensions;

namespace XUnitTests
{
    public class TheoryTest
    {
        [Theory]
        [InlineData("Hello", "World", "Hello World")]
        [InlineData("You", "Me", "You Me")]
        public void UsingInlineData(string firstWord, string secondWord, string concatenated)
        {
            Assert.Equal(concatenated, firstWord + " " + secondWord);
        }

        [Theory, MemberData("ConcatenationData")]
        public void UsingPropertyData(string firstWord, string secondWord, string concatenated)
        {
            Assert.Equal(concatenated, firstWord + " " + secondWord);
        }

        public static IEnumerable<object[]> ConcatenationData
        {
            get
            {
                return new[] {
                new object[] { "Hello", "World", "Hello World" },
                new object[] { "You", "Me", "You Me" },
            };
            }
        }

        [Theory, ClassData(typeof(ConcatenationDataFactory))]
        public void UsingClassData(string firstWord, string secondWord, string concatenated)
        {
            Assert.Equal(concatenated, firstWord + " " + secondWord);
        }

    }

    class ConcatenationDataFactory : IEnumerable<object[]>
    {
        private readonly List<object[]> data = new List<object[]>
        {
             new object[] { "Hello", "World", "Hello World" },
             new object[] { "You", "Me", "You Me" }
        };

        public IEnumerator<object[]> GetEnumerator()
        {
            return data.GetEnumerator();
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }
    }
}
