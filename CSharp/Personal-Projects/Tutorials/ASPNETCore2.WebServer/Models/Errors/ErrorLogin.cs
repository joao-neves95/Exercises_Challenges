﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace WebServer.Models
{
    public class ErrorLogin
    {
        private const string ERROR = "Invalid login attempt.";

        public string Error
        {
            get { return ERROR; }
        }

    }
}