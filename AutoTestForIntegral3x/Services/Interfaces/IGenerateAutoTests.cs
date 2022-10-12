using System.Collections.Generic;
using System.Threading.Tasks;
using AutoTestForIntegral3x.Models;

namespace AutoTestForIntegral3x.Services.Interfaces
{
    public interface IGenerateAutoTests
    {
        Task<ICollection<ResultTest>> GetPositiveResultTests(SettingsAutoTest settings);
        Task<ICollection<ResultTest>> GetNegativeResultTests(SettingsAutoTest settings);
    }
}
