using Autofac;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using AutoTestForIntegral3x.Interfaces;
using AutoTestForIntegral3x.Services;
using AutoTestForIntegral3x.Services.Interfaces;

namespace AutoTestForIntegral3x.Autofac
{
    internal class ServicesModule : Module
    {
        protected override void Load(ContainerBuilder builder)
        {
            builder.RegisterType<ProgramProcess>().As<IProgramProcess>();
            builder.RegisterType<GenerateRandomInputData>().As<IGenerateRandomInputData>();
            builder.Register(c => new GenerateAutoTests(
                c.Resolve<IGenerateRandomInputData>(), c.Resolve<IProgramProcess>()))
                .As<IGenerateAutoTests>();
        }
    }
}
