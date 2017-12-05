/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


import org.junit.Assert;

import junit.framework.TestCase;



/**
 * Performs Validation Test for url validations.
 *
 * @version $Revision: 1128446 $ $Date: 2011-05-27 13:29:27 -0700 (Fri, 27 May 2011) $
 */
public class UrlValidatorTest extends TestCase {

   private boolean printStatus = false;
   private boolean printIndex = false;//print index that indicates current scheme,host,port,path, query test were using.

   public UrlValidatorTest(String testName) {
      super(testName);
   }
   

   public void testManualTest()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println(urlVal.isValid("http://www.amazon.com"));
	   UrlValidator urlVal2 = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println(urlVal2.isValid("com"));
	   UrlValidator urlVal3 = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println(urlVal3.isValid("https://///www.google.com"));
	   assertTrue(urlVal.isValid("http://www.amazon.com"));
	   //assertFalse(urlVal2.isValid("cmo"));
	   //assertTrue(urlVal3.isValid("http://www.amazon.com:65535"));
	   UrlValidator urlVal4 = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   assertTrue(urlVal4.isValid("http://www.amazon.com:655"));
	   UrlValidator urlVal5 = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   assertTrue(urlVal5.isValid("http://www.amazon.com:999"));
	   UrlValidator urlVal6 = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	  // assertTrue(urlVal6.isValid("http://www.amazon.com:1000"));
   }
     
   public void testValidPortRange(){
	   UrlValidator validator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES); 
	   for (int i = 0; i < 1000; i++) {
		   String url = "http://www.amazon.com:";
		   String port = Integer.toString(i);
		   String concat = url.concat(port);
		   System.out.println(concat);
		   assertTrue(validator.isValid(concat));
	   }
   }
   public void testInValidPortRange(){
	   UrlValidator validator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES); 
	   for (int i = 1000; i < 65536; i++) {
		   String url = "http://www.amazon.com:";
		   String port = Integer.toString(i);
		   String concat = url.concat(port);
		   System.out.println(concat);
		   assertFalse(validator.isValid(concat));
	   }
   }
   public void testThreshold(){
	   UrlValidator validator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES); 
	   for (int i = 999; i < 1001; i++) {
		   String url = "http://www.amazon.com:";
		   String port = Integer.toString(i);
		   String concat = url.concat(port);
		   System.out.println(concat);
		   assertTrue(validator.isValid(concat));
	   }
   }
   public void testManualTest2()
   {
	  UrlValidator urlVal = new UrlValidator();
	   
	   System.out.println("\n\nMANUAL TESTING");
	   
	   System.out.println("Testing http://oregonstate.edu");
	   System.out.println("Returned: " + urlVal.isValid("http://oregonstate.edu") + "  Expected: true");
	   

 	   System.out.println("Testing http://oregonstate.du");
 	   System.out.println("Returned: " + urlVal.isValid("http://oregonstate.du") + "  Expected: false");
 	   

 	   System.out.println("Testing www.google.ccom");
 	   System.out.println("Returned: " + urlVal.isValid("www.google.ccom") + "  Expected: false");
	   

 	   System.out.println("Testing http://drive.google.com");
 	   System.out.println("Returned: " + urlVal.isValid("http://drive.google.com") + " Expected: true");
 	   

 	   System.out.println("Testing https://mail.google.com/mail/");
 	   System.out.println("Returned: " + urlVal.isValid("https://mail.google.com/mail/") + "  Expected: true");
 	   
	   
 	   System.out.println("Testing https://wwww.google.com");
 	   System.out.println("Returned: " + urlVal.isValid("https://wwww.google.com") + "  Expected: false");
 	   	   

 	   System.out.println("Testing http://192.168.0.1");
 	   System.out.println("Return: " + urlVal.isValid("http://192.168.0.1") + " Expected: true");
 	   

 	   System.out.println("Testing http://192.1688.0.1");
 	   System.out.println("Return: " + urlVal.isValid("http://192.1688.0.1") + " Expected: false");
   }
   
   public void testYourFirstPartition()
   {
 	   UrlValidator urlVal = new UrlValidator();
 	   
 	   System.out.println("\n\nFIRST PARTITION TESTING");
 	  
 	   //Testing the first partition - the URL Scheme
 	   System.out.println("Testing ftp");
 	   System.out.println("Returned: " + urlVal.isValidScheme("ftp") + "  Expected: true");
 	   
 	   System.out.println("Testing httpss");
 	   System.out.println("Returned: " + urlVal.isValidScheme("httpss") + "  Expected: false");
 	   
 	   System.out.println("Testing htttp");
 	   System.out.println("Returned: " + urlVal.isValidScheme("htttp") + "  Expected: false");
 	   
 	   System.out.println("Testing https");
 	   System.out.println("Returned: " + urlVal.isValidScheme("https") + "  Expected: true");
	   
 	   System.out.println("Testing ftp://");
 	   System.out.println("Returned: " + urlVal.isValidScheme("ftp://") + "  Expected: false");
 	   
 	   System.out.println("Testing ftp:/");
 	   System.out.println("Returned: " + urlVal.isValidScheme("fttp;/") + "  Expected: false");
 	   
 	   System.out.println("Testing ttp");
 	   System.out.println("Returned: " + urlVal.isValidScheme("ttp") + "  Expected: false");
 	   
 	   System.out.println("Testing http");
 	   System.out.println("Returned: " + urlVal.isValidScheme("http") + "  Expected: true");
 	   
 	   System.out.println("Testing https");
 	   System.out.println("Returned: " + urlVal.isValidScheme("https") + "  Expected: true");
    }
   
   public void testYourSecondPartition()
   {
	   UrlValidator urlVal = new UrlValidator();
	   
	   System.out.println("\n\nSECOND PARTITION TESTING");
	   
 	   //Testing the second partition - the URL Authority
 	   System.out.println("Testing www.oregonstate.edu");
 	   System.out.println("Returned: " + urlVal.isValidAuthority("www.oregonstate.edu") + "  Expected: true");
 	   
 	   System.out.println("Testing www.oregonstate.du");
 	   System.out.println("Returned: " + urlVal.isValidAuthority("www.oregonstate.du") + "  Expected: false");
 	   
 	   System.out.println("Testing wwworegonstate.edu");
 	   System.out.println("Returned: " + urlVal.isValidAuthority("wwworegonstate.edu") + "  Expected: false");
 	   
 	   System.out.println("Testing wwww.oregonstate.eedu");
 	   System.out.println("Returned: " + urlVal.isValidAuthority("wwww.oregonstate.eedu") + "  Expected: false");
 	   
 	   System.out.println("Testing ");
 	   System.out.println("Returned: " + urlVal.isValidAuthority("") + "  Expected: false");
 	   
 	   System.out.println("Testing wwww.oregonstate..edu");
 	   System.out.println("Returned: " + urlVal.isValidAuthority("wwww.oregonstate..edu") + "  Expected: false");
 	   
 	  System.out.println("Testing ww.oregonstate.edu");
	   System.out.println("Returned: " + urlVal.isValidAuthority("ww.oregonstate.edu") + "  Expected: false");
   }   

}
